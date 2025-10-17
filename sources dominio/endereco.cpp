#include "header dominios/endereco.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isalpha, isdigit

// Implementação do método de validação
void Endereco::validar(const std::string& valorEndereco) {
    if (valorEndereco.length() < 5 || valorEndereco.length() > 30) {
        throw std::invalid_argument("O endereco deve ter entre 5 e 30 caracteres.");
    }

    if (valorEndereco.front() == ',' || valorEndereco.front() == '.' || valorEndereco.front() == ' ') {
        throw std::invalid_argument("O primeiro caracter nao pode ser virgula, ponto ou espaco em branco.");
    }
    if (valorEndereco.back() == ',' || valorEndereco.back() == '.' || valorEndereco.back() == ' ') {
        throw std::invalid_argument("O ultimo caracter nao pode ser virgula, ponto ou espaco em branco.");
    }

    for (size_t i = 0; i < valorEndereco.length(); ++i) {
        char caractere = valorEndereco[i];

        if (!isalpha(caractere) && !isdigit(caractere) && caractere != ' ' && caractere != ',' && caractere != '.') {
            throw std::invalid_argument("Caracter invalido. Permitidos: letras, digitos, espaco, virgula e ponto.");
        }

        if (i + 1 < valorEndereco.length()) {
            char proximo_caractere = valorEndereco[i + 1];
            if (caractere == ' ') {
                if (!isalpha(proximo_caractere) && !isdigit(proximo_caractere)) {
                    throw std::invalid_argument("Espaco deve ser seguido de digito ou letra.");
                }
            }
            if (caractere == ',') {
                if (proximo_caractere == ',' || proximo_caractere == '.') {
                    throw std::invalid_argument("Virgula nao pode ser seguida por virgula ou ponto.");
                }
            }
            if (caractere == '.') {
                if (proximo_caractere == ',' || proximo_caractere == '.') {
                    throw std::invalid_argument("Ponto nao pode ser seguido por virgula ou ponto.");
                }
            }
        }
    }
}

// Implementação do construtor
Endereco::Endereco(const std::string& valorEndereco) {
    validar(valorEndereco);
    this->endereco = valorEndereco;
}

// Implementação do método set
void Endereco::setEndereco(const std::string& valorEndereco) {
    validar(valorEndereco);
    this->endereco = valorEndereco;
}

// Implementação do método get
std::string Endereco::getEndereco() const {
    return this->endereco;
}
