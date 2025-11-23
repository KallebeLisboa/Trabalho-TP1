#ifndef CONTROLADORAAPRESENTACAO_HPP_INCLUDED
#define CONTROLADORAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>

#include "ControladoraHotel.hpp"
#include "ControladoraQuarto.hpp"
#include "ControladoraReserva.hpp"
#include "ControladoraHospede.hpp"
#include "ControladoraUsuario.hpp"

// INCLUDES DAS INTERFACES
#include "IServicoUsuario.hpp"
#include "IServicoHotel.hpp" // <--- Importante

using namespace std;

class ControladoraApresentacao {
private:
    IServicoUsuario* servicoUsuario;

    ControladoraHotel controladoraHotel;
    ControladoraQuarto controladoraQuarto;
    ControladoraReserva controladoraReserva;
    ControladoraHospede controladoraHospede;
    ControladoraUsuario controladoraUsuario;

    bool criarConta();
    bool autenticar();
    void mostrarMenuPrincipal();

public:
    ControladoraApresentacao() : servicoUsuario(nullptr) {}

    // Configura Gerente
    void configurarServicos(IServicoUsuario* srvUsuario) {
        this->servicoUsuario = srvUsuario;
        controladoraUsuario.setServicoUsuario(srvUsuario);
    }

    // Configura Hotel (O método que estava faltando!)
    void configurarServicosHotel(IServicoHotel* srvHotel) {
        controladoraHotel.setServicoHotel(srvHotel);
    }

    void executar();
};

#endif // CONTROLADORAAPRESENTACAO_HPP_INCLUDED
