#ifndef CONTROLADORAHOSPEDE_HPP_INCLUDED
#define CONTROLADORAHOSPEDE_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ControladoraHospede {
private:
    // **INTEGRACAO FUTURA:**
    // I_ServicoHospede* servicoHospede; // Interface do Modulo de Servico de Hospede

    void exibirOpcoes();
    void criarHospede();
    void lerHospede();
    void editarHospede();
    void excluirHospede();
    void listarHospedes();

public:
    void executar(); // Metodo principal chamado pelo Menu Principal
};

#endif // CONTROLADORAHOSPEDE_HPP_INCLUDED
