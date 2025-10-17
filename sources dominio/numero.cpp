#include "header dominios/numero.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit
#include <string>    // Para std::stoi

// Implementação do método de validação
void Numero::validar(const std::string& valorNumero) {
    // A especificação diz que o número deve ter 3 dígitos (001 a 999)
    if (valorNumero.length() != 3) {
        throw std::invalid_argument("O numero deve conter exatamente 3 digitos.");
    }

    // Verifica se todos os caracteres são dígitos
    for (char caractere : valorNumero) {
        if (!isdigit(caractere)) {
            throw std::invalid_argument("Todos os caracteres devem ser digitos numericos.");
        }
    }

    // Converte para inteiro para verificar a faixa de valor
    int valorNumerico = std::stoi(valorNumero);
    if (valorNumerico < 1 || valorNumerico > 999) {
        throw std::invalid_argument("O valor do numero deve ser de 001 a 999.");
    }
}

// Implementação do construtor
Numero::Numero(const std::string& valorNumero) {
    validar(valorNumero);
    this->numero = valorNumero;
}

// Implementação do método set
void Numero::setNumero(const std::string& valorNumero) {
    validar(valorNumero);
    this->numero = valorNumero;
}

// Implementação do método get
std::string Numero::getNumero() const {
    return this->numero;
}
