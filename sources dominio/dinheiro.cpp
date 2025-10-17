#include "header dominios/dinheiro.hpp"
#include <stdexcept> // Para std::invalid_argument

// Implementao do método de validao
void Dinheiro::validar(int valorEmCentavos) {
    // O valor em centavos deve estar entre 1 (R$ 0,01) e 100000000 (R$ 1.000.000,00)
    if (valorEmCentavos < 1 || valorEmCentavos > 100000000) {
        throw std::invalid_argument("Valor deve estar entre 0,01 a 1.000.000,00.");
    }
}

// Implementao do construtor
Dinheiro::Dinheiro(double valor) {
    // Converte o double para centavos (int), arredondando corretamente
    int valorEmCentavos = static_cast<int>(valor * 100.0 + 0.5);
    validar(valorEmCentavos);
    this->centavos = valorEmCentavos;
}

// Implementação do método set
void Dinheiro::setDinheiro(double valor) {
    int valorEmCentavos = static_cast<int>(valor * 100.0 + 0.5);
    validar(valorEmCentavos);
    this->centavos = valorEmCentavos;
}

// Implementao do método get
double Dinheiro::getDinheiro() const {
    // Converte de volta os centavos (int) para o formato double (reais)
    return static_cast<double>(this->centavos) / 100.0;
}
