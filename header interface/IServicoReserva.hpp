#ifndef ISERVICORESERVA_HPP
#define ISERVICORESERVA_HPP

#include <string>
#include <map>
#include "../header entidades/reserva.hpp"

using namespace std;

class IServicoReserva {
public:
    virtual ~IServicoReserva() {}

    virtual void criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto) = 0;
    virtual Reserva* pesquisarReserva(string codigo) = 0;

    // --- MÉTODO ALTERADO (Agora pede o codigoHotel) ---
    virtual map<string, Reserva*> listarReservasDoHotel(string codigoHotel) = 0;

    virtual void atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor, string novoNumeroQuarto) = 0;
    virtual void excluirReserva(string codigo) = 0;
};

#endif
