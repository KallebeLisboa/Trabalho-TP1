#include "header dominios/ramal.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit
#include <string>    // Para std::stoi

// Implementação do m�todo de validação
void Ramal::validar(const std::string& valorRamal) {
    // A especificação diz que o ramal deve ter 2 dígitos (00 a 50)
    if (valorRamal.length() != 2) {
        throw std::invalid_argument("O ramal deve conter exatamente 2 digitos.");
    }

    // Verifica se todos os caracteres são dígitos
    for (char caractere : valorRamal) {
        if (!isdigit(caractere)) {
            throw std::invalid_argument("Todos os caracteres do ramal devem ser digitos numericos.");
        }
    }

    // Converte para inteiro para verificar a faixa de valor
    int valorNumerico = std::stoi(valorRamal);
    if (valorNumerico < 0 || valorNumerico > 50) {
        throw std::invalid_argument("O valor do ramal deve ser de 00 a 50.");
    }
}

// Implementação do construtor
Ramal::Ramal(const std::string& valorRamal) {
    validar(valorRamal);
    this->ramal = valorRamal;
}

// Implementação do método set
void Ramal::setRamal(const std::string& valorRamal) {
    validar(valorRamal);
    this->ramal = valorRamal;
}

// Implementação do método get
std::string Ramal::getRamal() const {
    return this->ramal;
}
