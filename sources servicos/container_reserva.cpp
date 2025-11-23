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

map<string, Reserva*> ContainerReserva::listarReservas() {
    return bancoDeReservas;
}

void ContainerReserva::atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor) {
    if (bancoDeReservas.count(codigo) == 0) throw runtime_error("Erro: Reserva nao encontrada.");

    Reserva* r = bancoDeReservas[codigo];
    
    r->setChegada(Data(novaDataEntrada));
    r->setPartida(Data(novaDataSaida));
    r->setValor(Dinheiro(novoValor));

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