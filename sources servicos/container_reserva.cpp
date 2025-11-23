#include "header servicos/container_reserva.hpp"
#include <stdexcept>
#include <iostream>

ContainerReserva::~ContainerReserva() {
    for (auto& par : bancoDeReservas) delete par.second;
    bancoDeReservas.clear();
}

void ContainerReserva::criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto) {
    if (bancoDeReservas.count(codigo) > 0) {
        throw runtime_error("Erro: Codigo de reserva ja existente.");
    }

    Reserva* novaReserva = new Reserva(
        Data(dataEntrada),
        Data(dataSaida),
        Dinheiro(valor),
        Codigo(codigo),
        Email(emailHospede),
        Numero(numeroQuarto),
        Codigo(codigoHotel)
    );

    bancoDeReservas[codigo] = novaReserva;
    cout << " > Sucesso: Reserva realizada." << endl;
}

// Implementação: Listar Reservas FILTRADAS por Hotel
map<string, Reserva*> ContainerReserva::listarReservasDoHotel(string codigoHotel) {
    map<string, Reserva*> filtro;

    // Itera sobre todas as reservas do banco
    for (auto const& par : bancoDeReservas) {
        Reserva* r = par.second;

        // Verifica se a reserva pertence ao hotel solicitado
        if (r->getCodigoHotel().getCodigo() == codigoHotel) {
            filtro[par.first] = r; // Adiciona ao mapa de filtro
        }
    }
    return filtro;
}

void ContainerReserva::atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor, string novoNumeroQuarto) {
    if (bancoDeReservas.count(codigo) == 0) {
        throw runtime_error("Erro: Reserva nao encontrada.");
    }

    Reserva* r = bancoDeReservas[codigo];

    // 1. Atualiza Chegada
    if (!novaDataEntrada.empty()) {
        r->setChegada(Data(novaDataEntrada));
    }

    // 2. Atualiza Partida
    if (!novaDataSaida.empty()) {
        r->setPartida(Data(novaDataSaida));
    }

    // 3. Atualiza Valor (Se for diferente de -1.0)
    if (novoValor != -1.0) {
        r->setValor(Dinheiro(novoValor));
    }

    // 4. Atualiza Quarto
    if (!novoNumeroQuarto.empty()) {
        r->setNumeroQuarto(Numero(novoNumeroQuarto));
    }

    cout << " > Sucesso: Reserva atualizada." << endl;
}

void ContainerReserva::excluirReserva(string codigo) {
    if (bancoDeReservas.count(codigo) > 0) {
        delete bancoDeReservas[codigo];
        bancoDeReservas.erase(codigo);
        cout << " > Sucesso: Reserva cancelada." << endl;
    } else {
        throw runtime_error("Erro: Reserva nao encontrada.");
    }
}

Reserva* ContainerReserva::pesquisarReserva(string codigo) {
    // Verifica se o código existe no mapa
    if (bancoDeReservas.count(codigo) > 0) {
        return bancoDeReservas[codigo];
    }
    return nullptr; // Retorna nulo se não encontrar
}
