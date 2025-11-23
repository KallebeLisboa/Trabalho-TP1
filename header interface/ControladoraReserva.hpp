#ifndef CONTROLADORARESERVA_HPP_INCLUDED
#define CONTROLADORARESERVA_HPP_INCLUDED

#include <iostream>
#include <string>
#include "IServicoReserva.hpp"

using namespace std;

class ControladoraReserva {
private:
    IServicoReserva* servicoReserva;

    void exibirOpcoes();
    void criarReserva();
    void lerReserva();
    void editarReserva();
    void excluirReserva();
    void listarReservas();

public:
    // Adicione o Setter
    void setServicoReserva(IServicoReserva* s) { servicoReserva = s; }

    void executar();
};

#endif // CONTROLADORARESERVA_HPP_INCLUDED
