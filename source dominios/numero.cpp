#include "header dominios/numero.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit
#include <string>    // Para std::stoi

// Implementação do método de validação
void Numero::validar(std::string const &numero){
            
    if(numero.length() != 3){ // Primeiro, confirma que é tem 3 caracteres. Ex: 007
        throw std::invalid_argument("O número deve conter exatamente 3 dígitos");
    }

    for(int i = 0;i < numero.length();i++){ // Depois, confirmar que é um número
        char caractere = numero[i];
        if(!(isdigit(caractere))){
            throw std::invalid_argument("Todos os caracteres devem ser dígitos numéricos");
        }
    }

    // Faria mais sentido ver primeiro se é número, porém, otimiza o programa analisar o if primeiro, pois o erro pode vir no loop for.

    int valorNumerico = std::stoi(numero);
    if(valorNumerico < 1){ // Por fim, vê se o número está no range (não pode ser 000)
        throw std::invalid_argument("O valor do número deve ser de 001 a 999");
    }
}

// Implementação do construtor
Numero::Numero(std::string numero){
    validar(numero);
    this->numero = numero;
};

// Implementação do método set
void Numero::setNumero(std::string numero) {
    validar(numero);
    this->numero = numero;
}

// Implementação do método get
std::string Numero::getNumero(){
    return this->numero;
}