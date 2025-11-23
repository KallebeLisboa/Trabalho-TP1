#include "header dominios/codigo.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit e islower

// Implementação do método de validação
void Codigo::validar(std::string const &codigo){

    if(!(codigo.length() == 10)){ // Tamanho do código
        throw std::invalid_argument("O código deve ter 10 caracteres.");
    }
    for (char caractere : codigo){
        if (!(isdigit(caractere)) && !(islower(caractere))){ // Se não for dígito ou se não for letra minúscula
            throw std::invalid_argument("Cada caractere deve ser uma letra minúscula (a-z) ou um dígito (0-9)");
        }
    }
};

// Implementação do construtor
Codigo::Codigo(std::string codigo){
    validar(codigo);
    this->codigo = codigo;
};

// Implementação do método set
void Codigo::setCodigo(std::string codigo){
    validar(codigo);
    this->codigo = codigo;
};

// Implementação do método get
std::string Codigo::getCodigo()const{
    return this->codigo;
};
