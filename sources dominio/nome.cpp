#include "header dominios/nome.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isupper, isalpha, isspace

// Implementação do método de validação
void Nome::validar(const std::string& valorNome) {
    if (valorNome.length() < 5 || valorNome.length() > 20) {
        throw std::invalid_argument("O nome deve ter entre 5 e 20 caracteres.");
    }
    if (valorNome.empty() || !isupper(valorNome[0])) {
        throw std::invalid_argument("O primeiro caractere de um nome deve ser uma letra maiuscula.");
    }
    if (isspace(valorNome.front()) || isspace(valorNome.back())) {
        throw std::invalid_argument("O nome nao pode comecar ou terminar com espaco.");
    }

    for (size_t i = 0; i < valorNome.length(); ++i) {
        char caractere = valorNome[i];

        if (!isspace(caractere) && !isalpha(caractere)) {
            throw std::invalid_argument("Caracter invalido. Permitidos apenas letras e espaco.");
        }

        if (isspace(caractere)) {
            // Verifica se o próximo caractere, se existir, é uma letra maiúscula
            if ((i + 1) < valorNome.length() && !isupper(valorNome[i + 1])) {
                throw std::invalid_argument("Espaco em branco deve ser seguido por uma letra maiuscula.");
            }
        }
    }
}

// Implementação do construtor
Nome::Nome(const std::string& valorNome) {
    validar(valorNome);
    this->nome = valorNome;
}

// Implementação do método set
void Nome::setNome(const std::string& valorNome) {
    validar(valorNome);
    this->nome = valorNome;
}

// Implementação do método get
std::string Nome::getNome() const {
    return this->nome;
}
