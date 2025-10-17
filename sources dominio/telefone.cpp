#include "header dominios/telefone.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit

// Implementação do método de validação
void Telefone::validar(const std::string& valorTelefone) {
    // Isso resulta em 15 caracteres: 1 sinal de '+' e 14 dígitos.
    if (valorTelefone.length() != 15 || valorTelefone.front() != '+') {
        throw std::invalid_argument("Formato invalido. Use o formato '+DDDDDDDDDDDDDD', onde D e um digito de 0 a 9.");
    }

    // Verifica se todos os caracteres após o '+' são dígitos
    for (size_t i = 1; i < valorTelefone.length(); ++i) {
        if (!isdigit(valorTelefone[i])) {
            throw std::invalid_argument("Formato invalido. Apenas o primeiro caractere pode ser '+' e os demais devem ser digitos.");
        }
    }
}

// Implementação do construtor
Telefone::Telefone(const std::string& valorTelefone) {
    validar(valorTelefone);
    this->telefone = valorTelefone;
}

// Implementação do método set
void Telefone::setTelefone(const std::string& valorTelefone) {
    validar(valorTelefone);
    this->telefone = valorTelefone;
}

// Implementação do método get
std::string Telefone::getTelefone() const {
    return this->telefone;
}
