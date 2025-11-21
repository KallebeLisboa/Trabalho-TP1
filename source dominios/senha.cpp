#include "header dominios/senha.hpp"
#include <stdexcept> // Para std::invalid_argument
#include <cctype>    // Para isalpha, isdigit, isupper, islower

// Implementação do método de validação
void Senha::validar(std::string const &senha){
    if(senha.length() != 5){
        throw std::invalid_argument("Senha deve conter 5 caracteres");
    };

    int letraLower, letraUpper, digito, charEspecial;
    letraLower = letraUpper = digito = charEspecial = 0; // Para analisar ser existe pelo menos uma letra minúscula (a-z), uma letra maiúscula (A-Z), um dígito (0-9) e um caracter especial.

    for(int i = 0;i < senha.length();i++){
        char caractere = senha[i];
        if(isalpha(caractere)) {
            if (i + 1 < senha.length()){
                if(isalpha(senha[i + 1])){
                    throw std::invalid_argument("Letra não pode ser seguida por letra");
                }
            }
            if(isupper(caractere)){
                letraUpper++;
            }
            else{
                letraLower++;
            }
        }
        else if(isdigit(caractere)) {
            if (i + 1 < senha.length()){
                if(isdigit(senha[i + 1])){
                    throw std::invalid_argument("Dígito não pode ser seguida por dígito");
                }
            }
            digito++;
        }
        else if(caractere == '!' || caractere == '"' || caractere == '#' ||
                caractere == '$' || caractere == '%' || caractere == '&' ||
                caractere == '?') {
            charEspecial++;
        }
        else{
            throw std::invalid_argument("Caracter pode ser letra (a-z ou A-Z), dígito (0-9) ou caracter especial ( ! \" # $ % & ? )");
        }

    };
    if (letraLower == 0 || letraUpper == 0 || digito == 0 || charEspecial == 0) { // Alguma das variáveis é 0
        throw std::invalid_argument("Senha deve conter pelo menos uma letra minúscula (a-z), uma letra maiúscula (A-Z), um dígito (0-9) e um caracter especial");
    };

};

// Implementação do construtor
Senha::Senha(std::string senha){
    validar(senha);
    this->senha = senha;
};

// Implementação do método set
void Senha::setSenha(std::string senha) {
    validar(senha);
    this->senha = senha;
}

// Implementação do método get
std::string Senha::getSenha(){
    return this->senha;
}