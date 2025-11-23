#ifndef HOTEL_HPP
#define HOTEL_HPP

// Inclusão das classes de domínio que serão atributos
#include "../header dominios/nome.hpp"
#include "../header dominios/endereco.hpp"
#include "../header dominios/telefone.hpp"
#include "../header dominios/codigo.hpp"


class Hotel {
private:
    // Atributos são instâncias das classes de Domínio
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo; // <<PK>> - Chave Primária

public:
    // Construtor
    Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo);

    // Métodos Get (Para acesso aos atributos)
    Nome getNome() const;
    Endereco getEndereco() const;
    Telefone getTelefone() const;
    Codigo getCodigo() const;

    // Métodos Set (Para modificar os atributos)
    // Não é possível editar dado que identifica registro (chave primária).
    void setNome(const Nome& nome);
    void setEndereco(const Endereco& endereco);
    void setTelefone(const Telefone& telefone);
};

#endif // HOTEL_HPP
