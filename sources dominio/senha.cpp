#include "header dominios/senha.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isalpha, isdigit, isupper, islower

// Implementação do método de validação
void Senha::validar(const std::string& valorSenha) {
    if (valorSenha.length() != 5) { 
        throw std::invalid_argument("Senha deve conter 5 caracteres.");
    }

    bool temMinuscula = false;
    bool temMaiuscula = false;
    bool temDigito = false;
    bool temEspecial = false;

    for (size_t i = 0; i < valorSenha.length(); ++i) {
        char caractere = valorSenha[i];
        char proximo_caractere = (i + 1 < valorSenha.length()) ? valorSenha[i + 1] : '\0';

        // Verifica a regra de não repetição de tipo
        if (isalpha(caractere) && isalpha(proximo_caractere)) {
            throw std::invalid_argument("Letra nao pode ser seguida por letra.");
        }
        if (isdigit(caractere) && isdigit(proximo_caractere)) {
            throw std::invalid_argument("Digito nao pode ser seguido por digito.");
        }

        // Valida o caractere e conta os tipos
        if (islower(caractere)) {
            temMinuscula = true;
        } else if (isupper(caractere)) {
            temMaiuscula = true;
        } else if (isdigit(caractere)) {
            temDigito = true;
        } else if (caractere == '!' || caractere == '"' || caractere == '#' ||
                   caractere == '$' || caractere == '%' || caractere == '&' ||
                   caractere == '?') {
            temEspecial = true;
        } else {
            // Se não for nenhum dos tipos válidos
            throw std::invalid_argument("Caracter invalido na senha. Use letras, digitos ou os especiais [! \" # $ % & ?].");
        }
    }

    // Verifica a regra de conter pelo menos um de cada tipo
    if (!temMinuscula || !temMaiuscula || !temDigito || !temEspecial) {
        throw std::invalid_argument("Senha deve conter pelo menos uma letra minuscula, uma maiuscula, um digito e um caracter especial.");
    }
}

// Implementação do construtor
Senha::Senha(const std::string& valorSenha) {
    validar(valorSenha);
    this->senha = valorSenha;
}

// Implementação do método set
void Senha::setSenha(const std::string& valorSenha) {
    validar(valorSenha);
    this->senha = valorSenha;
}

// Implementação do método get
std::string Senha::getSenha() const {
    return this->senha;
}
