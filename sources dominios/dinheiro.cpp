#include "header dominios/dinheiro.hpp"
#include <stdexcept>

// Implementao do método de validao
void Dinheiro::validar(int const &dinheiro){
    // O valor em centavos deve estar entre 1 (R$ 0,01) e 100000000 (R$ 1.000.000,00)
    if(dinheiro < 1 || dinheiro > 100000000){
        throw std::invalid_argument("Valor deve estar entre 0,01 a 1.000.000,00");
    };
};

// Implementao do construtor
Dinheiro::Dinheiro(double dinheiro){
    int centavos = static_cast<int>(dinheiro * 100.0 + 0.5);
    validar(centavos);
    this->dinheiro = centavos;
};

// Implementação do método set
void Dinheiro::setDinheiro(double dinheiro){
    int centavos = static_cast<int>(dinheiro * 100.0 + 0.5);
    validar(centavos);
    this->dinheiro = centavos;
};

// Implementao do método get
double Dinheiro::getDinheiro(){
    return static_cast<double>(this->dinheiro) / 100.0;
};
