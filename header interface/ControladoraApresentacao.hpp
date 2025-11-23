#ifndef CONTROLADORAAPRESENTACAO_HPP_INCLUDED
#define CONTROLADORAAPRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>

// Includes das controladoras
#include "ControladoraHotel.hpp"
#include "ControladoraQuarto.hpp"
#include "ControladoraReserva.hpp"
#include "ControladoraHospede.hpp"
#include "ControladoraUsuario.hpp"

// INCLUDES DAS INTERFACES DE SERVIÇO
#include "IServicoUsuario.hpp"
#include "IServicoHotel.hpp"
#include "IServicoQuarto.hpp"
#include "IServicoReserva.hpp"
#include "IServicoHospede.hpp"

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

    // 1. Configura Serviço de Usuário
    void configurarServicos(IServicoUsuario* srvUsuario) {
        this->servicoUsuario = srvUsuario;
        controladoraUsuario.setServicoUsuario(srvUsuario);
    }

    // 2. Configura Serviço de Hotel
    void configurarServicosHotel(IServicoHotel* srvHotel) {
        controladoraHotel.setServicoHotel(srvHotel);
    }

    // 3. Configura Serviço de Quarto
    void configurarServicosQuarto(IServicoQuarto* srvQuarto) {
        controladoraQuarto.setServicoQuarto(srvQuarto);
    }

    // 4. Configura Serviço de Reserva (O QUE ESTAVA FALTANDO)
    void configurarServicosReserva(IServicoReserva* srvReserva) {
        controladoraReserva.setServicoReserva(srvReserva);
    }

    // 5. Configura Serviço de Hospede (NOVO - PASSO 5)
    void configurarServicosHospede(IServicoHospede* srvHospede) {
        controladoraHospede.setServicoHospede(srvHospede);
    }

    void executar();
};

#endif // CONTROLADORAAPRESENTACAO_HPP_INCLUDED
