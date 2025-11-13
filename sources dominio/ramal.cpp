#include "header dominios/ramal.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit
#include <string>    // Para std::stoi

// Implementação do m�todo de validação
void Ramal::validar(std::string const &ramal){
            
    if(ramal.length() != 2){ // Primeiro, confirma que é tem 2 caracteres. Ex: 07
        throw std::invalid_argument("O ramal deve conter exatamente 2 dígitos");
    }

    for(int i = 0;i < ramal.length();i++){ // Depois, confirmar que é um número
        char caractere = ramal[i];
        if(!(isdigit(caractere))){
            throw std::invalid_argument("Todos os caracteres devem ser dígitos numéricos");
        }
    }

    // Faria mais sentido ver primeiro se é número, porém, otimiza o programa analisar o if primeiro, pois o erro pode vir no loop for.

    int valorNumerico = std::stoi(ramal);
    if(valorNumerico > 50){ // Por fim, vê se o número está no range (não pode ser maior que 50)
        throw std::invalid_argument("O valor do ramal deve ser de 00 a 50");
    }
}

// Implementação do construtor
Ramal::Ramal(std::string ramal){
    validar(ramal);
    this->ramal = ramal;
};

// Implementação do método set
void Ramal::setRamal(std::string ramal) {
    validar(ramal);
    this->ramal = ramal;
}

// Implementação do método get
std::string Ramal::getRamal(){
    return this->ramal;
}
