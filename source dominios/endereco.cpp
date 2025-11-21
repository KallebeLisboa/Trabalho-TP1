#include "header dominios/endereco.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isalpha, isdigit

// Implementação do método de validação
void Endereco::validar(std::string const &endereco){
    if(endereco.length() < 5 || endereco.length() > 30){
        throw std::invalid_argument("O endereço deve ter entre 5 e 30 caracteres.");
    };

    if(endereco.front() == ',' || endereco.front() == '.' || endereco.front() == ' '){ // Vírgula, ponto ou espaço em branco no primeiro caractere
        throw std::invalid_argument("O primeiro caracter não pode ser vírgula, ponto ou espaço em branco");
    }
    if(endereco.back() == ',' || endereco.back() == '.' || endereco.back() == ' '){// Vírgula, ponto ou espaço em branco no último caractere
        throw std::invalid_argument("O último caracter não pode ser vírgula, ponto ou espaço em branco.");
    };

    for(int i = 0; i < endereco.length();i++){
        char caractere = endereco[i];
            
            if(!((isalpha(caractere)) || (isdigit(caractere) || (caractere == ' ') || (caractere == ',') || (caractere == '.')))){
                throw std::invalid_argument("Caracter pode ser letra (a-z ou A-Z), dígito (0-9), vírgula, ponto ou espaço  em branco");
            };
            if (i + 1 < endereco.length()) {
                if(caractere == ' '){
                    if(!(isalpha(endereco[i+1]) || isdigit(endereco[i+1]))){
                        throw std::invalid_argument("Espaço deve ser seguido de dígito ou letra");  
                    };
                };
                if(caractere == ','){
                    if(endereco[i+1] == ',' || endereco[i+1] == '.'){
                        throw std::invalid_argument("Vírgula não pode ser seguida por vírgula ou ponto");  
                    };
                };
                if(caractere == '.'){
                    if(endereco[i+1] == ',' || endereco[i+1] == '.'){
                        throw std::invalid_argument("Ponto não pode ser seguida por vírgula ou ponto");  
                    };
                };
            };
    };

};

// Implementação do construtor
Endereco::Endereco(std::string endereco){
    validar(endereco);
    this->endereco = endereco;
};

// Implementação do método set
void Endereco::setEndereco(std::string endereco){
    validar(endereco);
    this->endereco = endereco;
};

// Implementação do método get
std::string Endereco::getEndereco(){
    return this->endereco;
};