#include "header dominios/codigo.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit e islower

// Implementação do método de validação
void Codigo::validar(const std::string& valorCodigo) {
    if (valorCodigo.length() != 10) {
        throw std::invalid_argument("O codigo deve ter 10 caracteres.");
    };
    for (char caractere : valorCodigo) {
        if (!(isdigit(caractere)) && !(islower(caractere))) {
            throw std::invalid_argument("Cada caractere deve ser uma letra minuscula (a-z) ou um digito (0-9).");
        };
    };
};

// Implementação do construtor
Codigo::Codigo(const std::string& valorCodigo) {
    validar(valorCodigo);
    this->codigo = valorCodigo;
}

// Implementação do método set
void Codigo::setCodigo(const std::string& valorCodigo) {
    validar(valorCodigo);
    this->codigo = valorCodigo;
}

// Implementação do método get
std::string Codigo::getCodigo() const {
    return this->codigo;
}
