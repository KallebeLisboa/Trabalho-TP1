#ifndef CONTAINER_HOTEL_HPP
#define CONTAINER_HOTEL_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>

// Inclusão das Entidades e Domínios necessários
#include "header entidades/hotel.hpp"
#include "header dominios/codigo.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/telefone.hpp"

using namespace std;

class ContainerHotel {
private:
    // Armazena os hotéis
    map<string, Hotel*> bancoDeHoteis;

public:
    // Destrutor para limpar memória
    ~ContainerHotel();

    // CRUD
    // Retorna true se criou com sucesso, pode lançar exceção de domínio
    void criarHotel(string codigo, string nome, string endereco, string telefone);
    
    // Retorna ponteiro para o Hotel ou nullptr se não achar
    Hotel* pesquisarHotel(string codigo);
    
    // Retorna todos os hotéis (útil para a TUI listar)
    map<string, Hotel*> listarHoteis();

    // Atualiza os dados. O código (PK) não muda.
    void atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone);
    
    void excluirHotel(string codigo);
};

#endif