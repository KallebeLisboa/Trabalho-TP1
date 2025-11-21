#include "header dominios/cartao.hpp"
#include <stdexcept> // Necessário para lançar exceções
#include <cctype>    // Para usar isdigit
#include <string>


// Implementação das funções auxiliares privadas (Algoritmo de Luhn)

// Passo 1.1: Se o número dobrado tem 2 dígitos, soma os dígitos individuais.
int Cartao::pegarDigito(const int numero){ 
    // Exemplo: Se numero for 16 (8*2), retorna 1 + 6 = 7.
    return numero % 10 + (numero / 10 % 10);
}

// Passo 1 e 2: Dobre cada segundo dígito da direita para esquerda e some.
int Cartao::somarDigitosPares(const std::string cartao){ 
    int soma = 0;
    // Itera de trás para frente, pulando de 2 em 2 (posições pares relativas ao fim)
    for(int i = cartao.length() - 2; i >= 0; i -= 2){
        // Converte char para int, dobra e processa o dígito
        soma += pegarDigito((cartao[i] - '0') * 2); 
    }
    return soma;
}

// Passo 3: Some todos digitos numerados ímpares da direita para a esquerda.
int Cartao::somarDigitosImpares(const std::string cartao){ 
    int soma = 0;
    // Itera de trás para frente, pulando de 2 em 2 (posições ímpares relativas ao fim)
    for(int i = cartao.length() - 1; i >= 0; i -= 2){
        soma += (cartao[i] - '0');
    }
    return soma;
}


// Implementação do método de validação principal

void Cartao::validar(std::string const &cartao){
    // Regra 1: O cartão deve ter exatamente 16 dígitos.
    if(cartao.length() != 16){
        throw std::invalid_argument("Numero de cartao deve conter 16 digitos.");
    }

    // Regra 2: O cartão deve conter apenas dígitos numéricos.
    for(size_t i = 0; i < cartao.length(); i++){
        if(!isdigit(cartao[i])){
            throw std::invalid_argument("Numero de cartao deve conter apenas digitos.");
        }
    }

    // Regra 3: Validação pelo Algoritmo de Luhn.
    // Passo 4: Some os resultados dos passos anteriores.
    int resultado = somarDigitosImpares(cartao) + somarDigitosPares(cartao);

    // Passo 5: Se o resultado for divisível por 10, é válido.
    if(resultado % 10 != 0){ 
        throw std::invalid_argument("Numero de cartao invalido (falha no algoritmo de Luhn).");
    }
}


// Implementação dos membros públicos


Cartao::Cartao(std::string cartao) {
    validar(cartao); // Valida antes de atribuir
    this->cartao = cartao;
}

void Cartao::setCartao(std::string cartao) {
    validar(cartao); // Valida antes de atribuir
    this->cartao = cartao;
}

std::string Cartao::getCartao() {
    return this->cartao;
}