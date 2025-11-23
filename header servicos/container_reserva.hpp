#ifndef CONTAINER_RESERVA_HPP
#define CONTAINER_RESERVA_HPP

#include <map>
#include <string>
#include "header entidades/reserva.hpp"
#include "../header interface/IServicoReserva.hpp" // <--- ADICIONE

// Domínios
#include "header dominios/data.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/codigo.hpp"
#include "header dominios/email.hpp"
#include "header dominios/numero.hpp"

using namespace std;

// ADICIONE A HERANÇA
class ContainerReserva : public IServicoReserva {
private:
    map<string, Reserva*> bancoDeReservas;

public:
    ~ContainerReserva();

    void criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto);

    // Adicionaremos a declaração do pesquisar aqui para os próximos passos
    Reserva* pesquisarReserva(string codigo);

    map<string, Reserva*> listarReservasDoHotel(string codigoHotel);

    void atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor, string novoNumeroQuarto);

    void excluirReserva(string codigo);
};

#endif
