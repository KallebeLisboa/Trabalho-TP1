#include "header dominios/email.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <algorithm> // Para std::count
#include <cctype>    // Para isdigit, islower, etc.
#include <string>

// Implementação do método de validação

void Email::validar(std::string const &email){

    // Regra 1: O e-mail deve conter exatamente um caractere '@' separador.
    int numeroDeArrobas = std::count(email.begin(), email.end(), '@');

    if(!(numeroDeArrobas == 1)){
        throw std::invalid_argument("Formato invalido. Use o formato 'parte-local@dominio'");
    }

    // Separa a string em duas partes: antes e depois do '@'
    int arroba = email.find('@');
    std::string parteLocal = email.substr(0, arroba);
    std::string dominio = email.substr(arroba + 1);

    // Validação da Parte Local
    
    // Regra: Não pode iniciar ou terminar com ponto ou hífen.
    if(parteLocal.front() == '-' || parteLocal.front() == '.'){ 
        throw std::invalid_argument("O primeiro caractere nao deve ser hifen ou ponto.");
    }
    if(parteLocal.back() == '-' || parteLocal.back() == '.'){
        throw std::invalid_argument("O ultimo caractere nao deve ser hifen ou ponto.");
    }
    
    // Regra: Caracteres permitidos e sequências proibidas.
    for (size_t i = 0; i < parteLocal.length(); i++){
        char caractere = parteLocal[i];
        
        // Verifica caracteres permitidos: letras minúsculas, dígitos, ponto ou hífen.
        if(!(isdigit(caractere) || islower(caractere) ||
        (caractere == '.') || (caractere == '-'))){
            throw std::invalid_argument("Parte local pode conter letra (a-z), digito (0-9) ou ponto(.) ou hifen (-)");
        }

        // Regra: Ponto ou hífen deve ser seguido por letra ou dígito (não pode haver ".." ou ".-").
        if (i + 1 < parteLocal.length()) {
            if(caractere == '.' || caractere == '-'){
                if(!(isalpha(parteLocal[i+1]) || isdigit(parteLocal[i+1]))){
                    throw std::invalid_argument("Hifen ou ponto deve ser seguido de digito ou letra");  
                }
            }
        }
    }

    // Regra: Comprimento máximo de 64 caracteres.
    if(parteLocal.length() < 1 || parteLocal.length() > 64){
        throw std::invalid_argument("Comprimento maximo da parte local e de 64 caracteres.");
    }

    // Validação do Domínio

    // Regra: Comprimento máximo de 255 caracteres.
    if (dominio.length() < 1|| dominio.length() > 255) {
        throw std::invalid_argument("Dominio do e-mail e invalido (vazio ou > 255 caracteres).");
    }

    // Regra: Não pode iniciar ou terminar com ponto ou hífen.
    if (dominio.front() == '-' || dominio.front() == '.') {
        throw std::invalid_argument("Dominio nao pode comecar com hifen ou ponto.");
    }
    if (dominio.back() == '-' || dominio.back() == '.') {
        throw std::invalid_argument("Dominio nao pode terminar com hifen ou ponto.");
    }

    // Regra: Caracteres permitidos e sequências no domínio.
    for (size_t i = 0; i < dominio.length(); i++) {
        char caractere = dominio[i];
        
        // Verifica caracteres permitidos.
        if (!(islower(caractere) || isdigit(caractere) || caractere == '.' || caractere == '-')) {
            throw std::invalid_argument("Dominio contem caractere invalido.");
        }
        
        // Regra: Pontos e hifens não podem ser consecutivos de forma inválida.
        if (i + 1 < dominio.length()) {
            if (caractere == '.') {
                if (dominio[i+1] == '.' || dominio[i+1] == '-') {
                    throw std::invalid_argument("No dominio, ponto nao pode ser seguido por hifen ou ponto.");
                }
            }
            if (caractere == '-') {
                if (dominio[i+1] == '.') {
                    throw std::invalid_argument("No dominio, hifen nao pode ser seguido por ponto.");
                }
            }
        }
    }
}

// Implementação do Construtor

Email::Email(std::string email){
    validar(email);
    this->email = email;
}

// Implementação do método set

void Email::setEmail(std::string email){
    validar(email);
    this->email = email;
}

// Implementação do método get

std::string Email::getEmail(){
    return this->email;
}