#ifndef ISERVICOQUARTO_HPP
#define ISERVICOQUARTO_HPP

#include <string>
#include <map>
#include "../header entidades/quarto.hpp"

using namespace std;

class IServicoQuarto {
public:
    virtual ~IServicoQuarto() {}

    // Métodos
    virtual void criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal) = 0;
    virtual Quarto* pesquisarQuarto(string codigoHotel, string numero) = 0;

    virtual map<string, Quarto*> listarQuartosDoHotel(string codigoHotel) = 0;
    virtual void atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal) = 0;
    virtual void excluirQuarto(string codigoHotel, string numero) = 0;
};

#endif
