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

// Interface
#include "../header interface/IServicoHotel.hpp"

using namespace std;

class ContainerHotel : public IServicoHotel {
private:
    // Armazena os hotéis
    map<string, Hotel*> bancoDeHoteis;

public:
    // Destrutor
    ~ContainerHotel();

    // Métodos CRUD (Apenas declaração, sem código aqui)
    void criarHotel(string codigo, string nome, string endereco, string telefone);

    Hotel* pesquisarHotel(string codigo);

    map<string, Hotel*> listarHoteis();

    void atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone);

    void excluirHotel(string codigo);
};

#endif
