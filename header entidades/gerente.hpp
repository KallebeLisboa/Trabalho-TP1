#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "Pessoa.hpp" // Inclui a classe base Pessoa
// Inclusão das classes de Domínio específicas
#include "header dominios/ramal.hpp"
#include "header dominios/senha.hpp"

class Gerente : public Pessoa {
private:
    // Atributos são instâncias das classes de Domínio específicas
    Ramal ramal;
    Senha senha;

public:
    // Construtor
    Gerente(const Nome& nome, const Email& email, const Ramal& ramal, const Senha& senha);

    // Métodos Get para atributos específicos
    Ramal getRamal() const;
    Senha getSenha() const;

    // Métodos Set para atributos específicos
    void setRamal(const Ramal& ramal);
    void setSenha(const Senha& senha);
    
};

#endif // GERENTE_HPP