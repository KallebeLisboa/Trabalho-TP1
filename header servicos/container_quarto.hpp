#ifndef CONTAINER_QUARTO_HPP
#define CONTAINER_QUARTO_HPP

#include <map>
#include <string>
#include "header entidades/quarto.hpp"
#include "../header interface/IServicoQuarto.hpp"

// Includes dos domínios necessários para instanciar no .cpp
#include "header dominios/numero.hpp"
#include "header dominios/capacidade.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/ramal.hpp"
#include "header dominios/codigo.hpp"

using namespace std;

class ContainerQuarto : public IServicoQuarto {
private:
    // Chave: "CODIGOHOTEL_NUMERO"
    map<string, Quarto*> bancoDeQuartos;

    // Helper para gerar chave composta
    string gerarChave(string codigoHotel, string numeroQuarto) {
        return codigoHotel + "_" + numeroQuarto;
    }

public:
    ~ContainerQuarto();

    void criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal);

    // --- NOVO MÉTODO DECLARADO ---
    Quarto* pesquisarQuarto(string codigoHotel, string numero);

    map<string, Quarto*> listarQuartosDoHotel(string codigoHotel);
    void atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal);
    void excluirQuarto(string codigoHotel, string numero);
};

#endif
