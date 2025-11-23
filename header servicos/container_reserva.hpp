#ifndef CONTAINER_RESERVA_HPP
#define CONTAINER_RESERVA_HPP

#include <map>
#include <string>
#include "header entidades/reserva.hpp"
#include "header dominios/data.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/codigo.hpp"
#include "header dominios/email.hpp"
#include "header dominios/numero.hpp"

using namespace std;

class ContainerReserva {
private:
    map<string, Reserva*> bancoDeReservas; // Chave: Código da Reserva

public:
    ~ContainerReserva();

    void criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto);
    
    map<string, Reserva*> listarReservas();

    void atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor);
    
    void excluirReserva(string codigo);
};

#endif