#ifndef CONTROLADORAQUARTO_HPP_INCLUDED
#define CONTROLADORAQUARTO_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ControladoraQuarto {
private:
    // **INTEGRAÇÃO FUTURA:**
    // I_ServicoQuarto* servicoQuarto; // Interface do Módulo de Serviço de Quarto

    void exibirOpcoes();
    void criarQuarto();
    void lerQuarto();
    void editarQuarto();
    void excluirQuarto();
    void listarQuartos();

public:
    void executar(); // Método principal chamado pelo Menu Principal
};

#endif // CONTROLADORAQUARTO_HPP_INCLUDED
