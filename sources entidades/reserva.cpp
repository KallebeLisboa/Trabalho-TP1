#include "header entidades/reserva.hpp"

// Construtor
// Inicializa todos os atributos de domínio usando a lista de inicialização
Reserva::Reserva(const Data& chegada, const Data& partida, const Dinheiro& valor, const Codigo& codigo, const Email& emailHospede, const Numero& numeroQuarto, const Codigo& codigoHotel)
    : chegada(chegada), partida(partida), valor(valor), codigo(codigo),
      emailHospede(emailHospede), numeroQuarto(numeroQuarto), codigoHotel(codigoHotel) {}

// Implementação dos Métodos Get
// Retornam a instância da classe de Domínio
Data Reserva::getChegada() const {
    return this->chegada;
}

Data Reserva::getPartida() const {
    return this->partida;
}

Dinheiro Reserva::getValor() const {
    return this->valor;
}

Codigo Reserva::getCodigo() const {
    return this->codigo;
}

Email Reserva::getEmailHospede() const {
    return this->emailHospede;
}

Numero Reserva::getNumeroQuarto() const {
    return this->numeroQuarto;
}

Codigo Reserva::getCodigoHotel() const {
    return this->codigoHotel;
}

// Implementação dos Métodos Set
// Atribui a nova instância do Domínio.
// A validação do formato do valor já ocorreu dentro do construtor
void Reserva::setChegada(const Data& chegada) {
    this->chegada = chegada;
}

void Reserva::setPartida(const Data& partida) {
    this->partida = partida;
}

void Reserva::setValor(const Dinheiro& valor) {
    this->valor = valor;
}

void Reserva::setEmailHospede(const Email& emailHospede) {
    this->emailHospede = emailHospede;
}

void Reserva::setNumeroQuarto(const Numero& numeroQuarto) {
    this->numeroQuarto = numeroQuarto;
}

void Reserva::setCodigoHotel(const Codigo& codigoHotel) {
    this->codigoHotel = codigoHotel;
}

