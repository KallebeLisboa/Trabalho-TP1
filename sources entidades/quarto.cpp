#include "header entidades/quarto.hpp"
#include <stdexcept>

// Construtor
// Inicializa todos os atributos na lista de inicialização, usando os construtores
// das classes de Domínio para garantir a validação.
Quarto::Quarto(const Codigo& codigoHotel, const Numero& numero, const Capacidade& capacidade, const Dinheiro& diaria, const Ramal& ramal)
    : codigoHotel(codigoHotel), numero(numero),capacidade(capacidade),diaria(diaria),ramal(ramal){}

// Implementação dos Métodos Get

Codigo Quarto::getCodigoHotel() const {
    return this->codigoHotel;
}

Numero Quarto::getNumero() const {
    return this->numero;
}

Capacidade Quarto::getCapacidade() const {
    return this->capacidade;
}

Dinheiro Quarto::getDiaria() const {
    return this->diaria;
}

Ramal Quarto::getRamal() const {
    return this->ramal;
}

// Implementação dos Métodos Set

void Quarto::setCodigoHotel(const Codigo& codigoHotel) {
    this->codigoHotel = codigoHotel;
}

void Quarto::setNumero(const Numero& numero) {
    this->numero = numero;
}

void Quarto::setCapacidade(const Capacidade& capacidade) {
    this->capacidade = capacidade;
}

void Quarto::setDiaria(const Dinheiro& diaria) {
    this->diaria = diaria;
}

void Quarto::setRamal(const Ramal& ramal) {
    this->ramal = ramal;
}
