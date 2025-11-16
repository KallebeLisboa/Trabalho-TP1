#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "header dominios/nome.hpp" 
#include "header dominios/email.hpp" 

//Classe Entidade que representa uma Pessoa no sistema.
//É a classe base para as Entidades Gerente e Hóspede (Herança). A chave primária (PK) é o atributo 'email'.

class Pessoa {
private:
    // Atributos são instâncias das classes de Domínio
    Nome nome;
    Email email; // <<PK>> - Chave Primária 

public:
    // Construtor
    // Recebe instâncias das classes de Domínio
    Pessoa(const Nome& nome, const Email& email);

    // Métodos Get
    Nome getNome() const;
    Email getEmail() const;

    // Métodos Set
    void setNome(const Nome& nome);
};

#endif // PESSOA_HPP