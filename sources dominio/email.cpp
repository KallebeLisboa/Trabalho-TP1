#include "header dominios/email.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <algorithm> // Para std::count
#include <cctype>    // Para isdigit, islower, etc.

// Implementação do método de validação
void Email::validar(const std::string& valorEmail) {
    size_t arroba_pos = valorEmail.find('@');

    if (arroba_pos == std::string::npos) {
        throw std::invalid_argument("Formato invalido. Email deve conter um '@'.");
    }

    if (std::count(valorEmail.begin(), valorEmail.end(), '@') != 1) {
        throw std::invalid_argument("Formato invalido. Email deve conter apenas um '@'.");
    }

    std::string parteLocal = valorEmail.substr(0, arroba_pos);
    std::string dominio = valorEmail.substr(arroba_pos + 1);

    // Validação da Parte Local
    if (parteLocal.empty() || parteLocal.length() > 64) {
        throw std::invalid_argument("Parte local do email e invalida (vazia ou > 64 caracteres).");
    }
    if (parteLocal.front() == '.' || parteLocal.front() == '-') {
        throw std::invalid_argument("Parte local nao pode comecar com ponto ou hifen.");
    }
    if (parteLocal.back() == '.' || parteLocal.back() == '-') {
        throw std::invalid_argument("Parte local nao pode terminar com ponto ou hifen.");
    }
    for (size_t i = 0; i < parteLocal.length(); ++i) {
        char c = parteLocal[i];
        if (!islower(c) && !isdigit(c) && c != '.' && c != '-') {
            throw std::invalid_argument("Parte local contem caractere invalido.");
        }
        if ((c == '.' || c == '-') && i + 1 < parteLocal.length()) {
            if (!islower(parteLocal[i + 1]) && !isdigit(parteLocal[i + 1])) {
                 throw std::invalid_argument("Ponto ou hifen na parte local deve ser seguido por letra ou digito.");
            }
        }
    }

    // Validação do Domínio
    if (dominio.empty() || dominio.length() > 255) {
        throw std::invalid_argument("Dominio do email e invalido (vazio ou > 255 caracteres).");
    }
    if (dominio.front() == '-' || dominio.front() == '.') {
        throw std::invalid_argument("Dominio nao pode comecar com hifen ou ponto.");
    }
    if (dominio.back() == '-' || dominio.back() == '.') {
        throw std::invalid_argument("Dominio nao pode terminar com hifen ou ponto.");
    }
    for (size_t i = 0; i < dominio.length(); ++i) {
        char c = dominio[i];
        if (!islower(c) && !isdigit(c) && c != '.' && c != '-') {
            throw std::invalid_argument("Dominio contem caractere invalido.");
        }
        if ((c == '.' || c == '-') && i + 1 < dominio.length()) {
            if (dominio[i + 1] == '.' || dominio[i + 1] == '-') {
                throw std::invalid_argument("No dominio, ponto ou hifen nao pode ser seguido por outro ponto ou hifen.");
            }
        }
    }
}

// Implementação do construtor
Email::Email(const std::string& valorEmail) {
    validar(valorEmail);
    this->email = valorEmail;
}

// Implementação do método set
void Email::setEmail(const std::string& valorEmail) {
    validar(valorEmail);
    this->email = valorEmail;
}

// Implementação do método get
std::string Email::getEmail() const {
    return this->email;
}
