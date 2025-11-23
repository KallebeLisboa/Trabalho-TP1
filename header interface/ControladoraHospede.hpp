#ifndef CONTROLADORAHOSPEDE_HPP_INCLUDED
#define CONTROLADORAHOSPEDE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "IServicoHospede.hpp" // <--- Necessário para a conexão

using namespace std;

class ControladoraHospede {
private:
    IServicoHospede* servicoHospede; // <--- O Ponteiro para o Banco de Dados

    void exibirOpcoes();
    void criarHospede();
    void lerHospede();
    void editarHospede();
    void excluirHospede();
    void listarHospedes();

public:
    // Setter para ligar o serviço
    void setServicoHospede(IServicoHospede* s) { servicoHospede = s; }

    void executar();
};

#endif // CONTROLADORAHOSPEDE_HPP_INCLUDED
