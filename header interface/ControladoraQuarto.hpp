#ifndef CONTROLADORAQUARTO_HPP_INCLUDED
#define CONTROLADORAQUARTO_HPP_INCLUDED

#include <iostream>
#include <string>
#include "IServicoQuarto.hpp"

using namespace std;

class ControladoraQuarto {
private:
    IServicoQuarto* servicoQuarto;

    void exibirOpcoes();
    void criarQuarto();
    void lerQuarto();
    void editarQuarto();
    void excluirQuarto();
    void listarQuartos();

public:
    // Adicione o Setter
    void setServicoQuarto(IServicoQuarto* s) { servicoQuarto = s; }

    void executar();
};

#endif // CONTROLADORAQUARTO_HPP_INCLUDED
