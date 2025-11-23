#include "header dominios/cartao.hpp"

// Passo 1. Dobre cada segundo dígito da direita para esquerda.
    // 1.1. Se o número dobrado tem 2 dígitos, divida-os
// Passo 2. Some todos os dígitos individuais do Passo 1 (e 1.1)
// Passo 3. Some todos digitos numerados ímpares da direita para a esquerda
// Passo 4. Some os passos 2 e 3
// Se o passo 4 for divisível por 10, o número de cartão é válido

// Implementação das funções auxiliares privadas

// Passo 1.1
int Cartao::pegarDigito(const int numero){ // Passo 1.1

    return numero % 10 + (numero / 10 % 10);
};

// Passo 1 e 2
int Cartao::somarDigitosPares(const std::string cartao){ // Passo 1 e 2

    int soma = 0;

    for(int i = cartao.length()-2; i >= 0;i-=2){
        soma += pegarDigito((cartao[i] - '0')*2); // Passo 2
    };
    return soma;
};

int Cartao::somarDigitosImpares(const std::string cartao){ // Passo 3

    int soma = 0;

    for(int i = cartao.length()-1; i >= 0;i-=2){
        soma += (cartao[i] - '0');
    };
    return soma;
};

// Validação completa (Passos 4 e 5)
void Cartao::validar(std::string const &cartao){

    if(!(cartao.length() == 16)){
        throw std::invalid_argument("Número de cartão deve contar 16 dígitos");
    };

    for(int i = 0; i < cartao.length();i++){
        if(!(isdigit(cartao[i]))){
            throw std::invalid_argument("Número de cartão deve conter apenas dígitos");
        }
    };

    int resultado = somarDigitosImpares(cartao) + somarDigitosPares(cartao); // Passo 4

    if(!(resultado % 10 == 0)){ // Passo 5
        throw std::invalid_argument("Número de cartão inválido");
    }
};

// Implementação dos membros públicos

Cartao::Cartao(std::string cartao) {
    validar(cartao); // Valida antes de atribuir
    this->cartao = cartao;
};

void Cartao::setCartao(std::string cartao) {
    validar(cartao); // Valida antes de atribuir
    this->cartao = cartao;
};

std::string Cartao::getCartao() {
    return this->cartao;
};
