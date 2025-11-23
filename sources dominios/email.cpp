#include "header dominios/email.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <algorithm> // Para std::count
#include <cctype>    // Para isdigit, islower, etc.

// Implementação do método de validação
void Email::validar(std::string const &email){

    int numeroDeArrobas = std::count(email.begin(), email.end(), '@');

    if(!(numeroDeArrobas == 1)){
        throw std::invalid_argument("Formato inválido. Use o formato 'parte-local@domínio'");
    };

    int arroba = email.find('@');

    std::string parteLocal = email.substr(0,arroba);
    std::string dominio = email.substr(arroba+1);

    // Validação da Parte Local
    if(parteLocal.front() == '-' || parteLocal.front() == '.'){ // Hífen ou ponto no primeiro caractere
        throw std::invalid_argument("O primeiro caractere não deve ser hífen ou ponto.");
    }
    if(parteLocal.back() == '-' || parteLocal.back() == '.'){// Hífen ou ponto no último caractere
        throw std::invalid_argument("O último caractere não deve ser hífen ou ponto.");
    };
    
    for (int i = 0; i < parteLocal.length(); i++){
        char caractere = parteLocal[i];
        if(!(isdigit(caractere) || islower(caractere) ||
        (caractere == '.') || (caractere == '-'))){
            throw std::invalid_argument("Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-)");
        };
        if (i + 1 < parteLocal.length()) {
            if(caractere == '.' || caractere == '-'){
                if(!(isalpha(parteLocal[i+1]) || isdigit(parteLocal[i+1]))){
                    throw std::invalid_argument("Hífen ou ponto deve ser seguido de dígito ou letra");  
                }
            }
        }
    }
    if(parteLocal.length() < 1 || parteLocal.length() > 64){
        throw std::invalid_argument("Comprimento máximo da parte local é de 64 caracteres.");
    }

    // Validação do Domínio

    if (dominio.length() < 1|| dominio.length() > 255) {
        throw std::invalid_argument("Domínio do e-mail é inválido (vazio ou > 255 caracteres).");
    }
    if (dominio.front() == '-' || dominio.front() == '.') {
        throw std::invalid_argument("Domínio não pode começar com hífen ou ponto.");
    }
    if (dominio.back() == '-' || dominio.back() == '.') {
        throw std::invalid_argument("Domínio não pode terminar com hífen ou ponto.");
    }

    for (int i = 0; i < dominio.length(); i++) {
        char caractere = dominio[i];
        if (!(islower(caractere) || isdigit(caractere) || caractere == '.' || caractere == '-')) {
            throw std::invalid_argument("Domínio contém caractere inválido.");
        }
        
        if (i + 1 < dominio.length()) {
            if (caractere == '.') {
                if (dominio[i+1] == '.' || dominio[i+1] == '-') {
                    throw std::invalid_argument("No domínio, ponto não pode ser seguido por hífen ou ponto.");
                }
            }
            if (caractere == '-') {
                if (dominio[i+1] == '.') {
                    throw std::invalid_argument("No domínio, hífen não pode ser seguido por ponto.");
                }
            }
        }
    }
};

// Implementação do construtor
Email::Email(std::string email){
    validar(email);
    this->email = email;
};

// Implementação do método set
void Email::setEmail(std::string email){
    validar(email);
    this->email = email;
};

// Implementação do método get
std::string Email::getEmail(){
    return this->email;
};