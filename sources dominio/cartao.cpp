#include "header dominios/cartao.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit

// Implementação dos métodos privados

int Cartao::pegarDigito(int numero) const {
    return numero % 10 + (numero / 10 % 10);
}

int Cartao::somarDigitosPares(const std::string& numeroCartao) const {
    int soma = 0;
    for (int i = numeroCartao.length() - 2; i >= 0; i -= 2) {
        soma += pegarDigito((numeroCartao[i] - '0') * 2);
    }
    return soma;
}

int Cartao::somarDigitosImpares(const std::string& numeroCartao) const {
    int soma = 0;
    for (int i = numeroCartao.length() - 1; i >= 0; i -= 2) {
        soma += (numeroCartao[i] - '0');
    }
    return soma;
}

void Cartao::validar(const std::string& numeroCartao) {
    if (numeroCartao.length() != 16) {
        throw std::invalid_argument("Numero de cartao deve conter 16 digitos.");
    }

    for (char digito : numeroCartao) {
        if (!isdigit(digito)) {
            throw std::invalid_argument("Numero de cartao deve conter apenas digitos.");
        }
    }

    int resultado = somarDigitosImpares(numeroCartao) + somarDigitosPares(numeroCartao);

    if (resultado % 10 != 0) {
        throw std::invalid_argument("Numero de cartao invalido.");
    }
}

// Implementação dos métodos públicos

Cartao::Cartao(const std::string& numeroCartao) {
    validar(numeroCartao);
    this->cartao = numeroCartao;
}

void Cartao::setCartao(const std::string& numeroCartao) {
    validar(numeroCartao);
    this->cartao = numeroCartao;
}

std::string Cartao::getCartao() const {
    return this->cartao;
}
