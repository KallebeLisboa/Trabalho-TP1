#include "ContainerReserva.hpp" // Ajuste o caminho se necessário
#include <stdexcept>
#include <iostream>

// Implementação do Destrutor

ContainerReserva::~ContainerReserva() {
    // Itera sobre o mapa para deletar os objetos Reserva alocados dinamicamente.
    // Isso é crucial para evitar vazamento de memória.
    for (auto& par : bancoDeReservas) {
        delete par.second; 
    }
    bancoDeReservas.clear(); // Limpa as referências do mapa.
}

// Implementação de Criar Reserva

void ContainerReserva::criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto) {
    // Verifica se já existe uma reserva com este código (Chave Primária).
    if (bancoDeReservas.count(codigo) > 0) {
        throw runtime_error("Erro: Codigo de reserva ja existente.");
    }

    // Instancia a nova Reserva.
    // Os construtores dos domínios (Data, Dinheiro, Codigo, Email, Numero) são chamados aqui.
    // Se qualquer formato for inválido (ex: data errada, email malformado), uma exceção é lançada.
    Reserva* novaReserva = new Reserva(
        Data(dataEntrada),
        Data(dataSaida),
        Dinheiro(valor),
        Codigo(codigo),
        Email(emailHospede),     // FK Hóspede
        Numero(numeroQuarto),    // FK Quarto
        Codigo(codigoHotel)      // FK Hotel
    );

    // Armazena no mapa usando o código como chave.
    bancoDeReservas[codigo] = novaReserva;
    
    cout << " > Sucesso: Reserva realizada." << endl;
}

// Implementação de Listar

map<string, Reserva*> ContainerReserva::listarReservas() {
    // Retorna o mapa completo para a camada de apresentação.
    return bancoDeReservas;
}

// Implementação de Atualizar

void ContainerReserva::atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor) {
    // Verifica se a reserva existe.
    if (bancoDeReservas.count(codigo) == 0) {
        throw runtime_error("Erro: Reserva nao encontrada.");
    }

    Reserva* r = bancoDeReservas[codigo];
    
    // Atualiza os dados mutáveis. 
    // Instancia novos objetos de Domínio para garantir a validação dos novos valores.
    r->setChegada(Data(novaDataEntrada));
    r->setPartida(Data(novaDataSaida));
    r->setValor(Dinheiro(novoValor));

    cout << " > Sucesso: Reserva atualizada." << endl;
}

// Implementação de Excluir

void ContainerReserva::excluirReserva(string codigo) {
    if (bancoDeReservas.count(codigo) > 0) {
        // 1. Libera a memória do objeto Reserva.
        delete bancoDeReservas[codigo];
        // 2. Remove a entrada do mapa.
        bancoDeReservas.erase(codigo);
        cout << " > Sucesso: Reserva cancelada." << endl;
    } else {
        throw runtime_error("Erro: Reserva nao encontrada.");
    }
}