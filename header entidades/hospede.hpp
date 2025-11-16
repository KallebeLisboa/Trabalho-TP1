#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "Pessoa.hpp" // Inclui a classe base Pessoa
// Inclusão das classes de Domínio específicas
#include "header dominios/endereco.hpp"
#include "header dominios/cartao.hpp"

class Hospede : public Pessoa {
private:
    // Atributos são instâncias das classes de Domínio específicas
    Endereco endereco;
    Cartao cartao;

public:
    // Construtor
    Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao);
    // Métodos Get para atributos específicos
    Endereco getEndereco() const;
    Cartao getCartao() const;

    // Métodos Set para atributos específicos
    void setEndereco(const Endereco& endereco);
    void setCartao(const Cartao& cartao);
    
};

#endif // HOSPEDE_HPP