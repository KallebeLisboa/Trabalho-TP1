#ifndef CONTROLADORAUSUARIO_HPP_INCLUDED
#define CONTROLADORAUSUARIO_HPP_INCLUDED

#include <iostream>
#include <string>
#include "IServicoUsuario.hpp" // <--- ADICIONADO: Inclui a interface

using namespace std;

class ControladoraUsuario {
private:
    // Ponteiro para a interface do serviço
    IServicoUsuario* servicoUsuario; // <--- ADICIONADO

    void exibirOpcoes();
    void lerConta();
    void editarConta();
    void excluirConta();

public:
    // Método para "ligar" o serviço ao controlador
    void setServicoUsuario(IServicoUsuario* s) { servicoUsuario = s; } // <--- ADICIONADO

    void executar();
};

#endif // CONTROLADORAUSUARIO_HPP_INCLUDED
