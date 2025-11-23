#ifndef CONTROLADORARESERVA_HPP_INCLUDED
#define CONTROLADORARESERVA_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ControladoraReserva {
private:
    // **INTEGRAÇÃO FUTURA:**
    // I_ServicoReserva* servicoReserva; // Interface do Módulo de Serviço de Reserva

    void exibirOpcoes();
    void criarReserva();
    void lerReserva();
    void editarReserva();
    void excluirReserva();
    void listarReservas();

public:
    void executar(); // Método principal chamado pelo Menu Principal
};

#endif // CONTROLADORARESERVA_HPP_INCLUDED
