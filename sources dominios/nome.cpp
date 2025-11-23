#include "header dominios/nome.hpp"
#include <stdexcept>
#include <cctype>

// Implementação do método de validação
void Nome::validar(std::string const &nome){

    if(nome.length() <5 || nome.length()>20){ // Tamanho do nome
        throw std::invalid_argument("O nome deve ter entre 5 e 20 caracteres.");
    }
    if (!isupper(nome[0])) {
        throw std::invalid_argument("O primeiro caractere deve ser uma letra maiúscula.");
    }
    if(nome.front() == ' '){ // Espaço no primeiro caractere
        throw std::invalid_argument("O primeiro caractere não deve ser espaço.");
    }
    if(nome.back() == ' '){// Espaço no último caractere
        throw std::invalid_argument("O último caractere não deve ser espaço.");
    }

    for (int i = 0; i < (nome.length()); i++)
    {
        char caractere = nome[i];

        if (!(isspace(caractere)) && !(isalpha(caractere))){ // Se não for espaço e se não for letra (símbolos, número...)
            throw std::invalid_argument("Cada caracter pode ser letra (a-z ou A-Z) ou espaço em branco");
        }

        if(isspace(caractere)){ // Se é um espaço, iniciasse um termo
            if((i+1) < nome.length() && !(isupper(nome[i+1]))){ // O termo que deve começar com letra maiúscula.
                throw std::invalid_argument("Espaço em branco deve ser seguido por uma letra maiúscula.");
            }
        }
    }

};

// Implementação do construtor
Nome::Nome(std::string nome) {
    validar(nome);
    this->nome = nome;
}

// Implementação do método set
void Nome::setNome(std::string nome) {
    validar(nome);
    this->nome = nome;
}

// Implementação do método get
std::string Nome::getNome(){
    return this->nome;
}
