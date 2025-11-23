#include "header dominios/telefone.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isdigit

// Implementação do método de validação
void Telefone::validar(std::string const &telefone){

    if(telefone.length() != 15 || telefone.front() != '+'){
        throw std::invalid_argument("Formato inválido. Use o formato de telefone '+DDDDDDDDDDDDDD', onde D é um dígito de 0 a 9");
    }

    for(int i = 1;i < telefone.length();i++){
        if(!(isdigit(telefone[i]))){
            throw std::invalid_argument("Formato inválido. Use o formato de telefone '+DDDDDDDDDDDDDD', onde D é um dígito de 0 a 9");
        };
    };
};

// Implementação do construtor
Telefone::Telefone(std::string telefone) {
    validar(telefone);
    this->telefone = telefone;
}

// Implementação do método set
void Telefone::setTelefone(std::string telefone) {
    validar(telefone);
    this->telefone = telefone;
}

// Implementação do método get
std::string Telefone::getTelefone(){
    return this->telefone;
}
