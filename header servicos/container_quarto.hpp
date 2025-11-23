#ifndef CONTAINER_QUARTO_HPP
#define CONTAINER_QUARTO_HPP

#include <map>
#include <string>
#include "header entidades/quarto.hpp"
#include "header dominios/numero.hpp"
#include "header dominios/capacidade.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/ramal.hpp"
#include "header dominios/codigo.hpp"

using namespace std;

class ContainerQuarto {
private:
    /*Não é definido uma chave única global para o quarto (só "número", que se repete entre hotéis),então
    eu usei uma chave composta no map: CODIGOHOTEL_NUMEROQUARTO (ex: "HOTEL1_101")*/

    // Chave: "CODIGOHOTEL_NUMERO"
    map<string, Quarto*> bancoDeQuartos;

    // Helper para gerar chave composta
    string gerarChave(string codigoHotel, string numeroQuarto) {
        return codigoHotel + "_" + numeroQuarto;
    }

public:
    ~ContainerQuarto();

    // Parâmetros primitivos para facilitar a camada de apresentação
    void criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal);
    
    map<string, Quarto*> listarQuartosDoHotel(string codigoHotel);
    
    void atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal);
    
    void excluirQuarto(string codigoHotel, string numero);
};

#endif