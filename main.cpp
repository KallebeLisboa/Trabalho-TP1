#include <iostream>

// 1. Incluir as Interfaces (Frente)
#include "header interface/ControladoraApresentacao.hpp"

// 2. Incluir os Serviços (Fundo/Banco de Dados)
#include "header servicos/container_gerente.hpp"
#include "header servicos/container_hotel.hpp"
#include "header servicos/container_quarto.hpp"
#include "header servicos/container_reserva.hpp"
#include "header servicos/container_hospede.hpp" // <--- ADICIONADO

using namespace std;

int main() {
    // PASSO 1: Criar os "Bancos de Dados" (Serviços)
    ContainerGerente* servicoGerente = new ContainerGerente();
    ContainerHotel* servicoHotel = new ContainerHotel();
    ContainerQuarto* servicoQuarto = new ContainerQuarto();
    ContainerReserva* servicoReserva = new ContainerReserva();
    ContainerHospede* servicoHospede = new ContainerHospede(); // <--- ADICIONADO

    // PASSO 2: Criar a Interface (Apresentação)
    ControladoraApresentacao app;

    // PASSO 3: Ligar os fios (Injeção de Dependência)
    app.configurarServicos(servicoGerente);
    app.configurarServicosHotel(servicoHotel);
    app.configurarServicosQuarto(servicoQuarto);
    app.configurarServicosReserva(servicoReserva);
    app.configurarServicosHospede(servicoHospede); // <--- ADICIONADO

    // PASSO 4: Rodar o Sistema
    app.executar();

    // PASSO 5: Limpeza de memória ao fechar
    delete servicoGerente;
    delete servicoHotel;
    delete servicoQuarto;
    delete servicoReserva;
    delete servicoHospede; // <--- ADICIONADO

    return 0;
}
