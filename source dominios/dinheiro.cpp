#include "header dominios/dinheiro.hpp"
#include <stdexcept> // Para std::invalid_argument

// Implementação do método de validação
void Dinheiro::validar(int const &dinheiro){
    // Regra de Negócio: O valor em centavos deve estar entre 1 (R$ 0,01) e 100.000.000 (R$ 1.000.000,00)
    if(dinheiro < 1 || dinheiro > 100000000){
        throw std::invalid_argument("Valor deve estar entre 0,01 a 1.000.000,00");
    }
}

// Implementação do Construtor
Dinheiro::Dinheiro(double dinheiro){
    // Converte double para centavos.
    // Adiciona 0.5 para garantir o arredondamento correto na conversão para int.
    int centavos = static_cast<int>(dinheiro * 100.0 + 0.5);
    
    validar(centavos);
    this->dinheiro = centavos;
}

// Implementação do método set
void Dinheiro::setDinheiro(double dinheiro){
    // Realiza a mesma conversão (com ajuste de arredondamento) e validação.
    int centavos = static_cast<int>(dinheiro * 100.0 + 0.5);
    
    validar(centavos);
    this->dinheiro = centavos;
}

// Implementação do método get
double Dinheiro::getDinheiro(){
    // Converte de volta de centavos (int) para reais (double).
    return static_cast<double>(this->dinheiro) / 100.0;
}