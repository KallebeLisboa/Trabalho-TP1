#include <iostream>

// 1. Incluir as Interfaces (Frente)
#include "header interface/ControladoraApresentacao.hpp"

// 2. Incluir os Serviços (Fundo/Banco de Dados)
#include "header servicos/container_gerente.hpp"
#include "header servicos/container_hotel.hpp"

using namespace std;

int main() {
    // PASSO 1: Criar os "Bancos de Dados" (Serviços)
    ContainerGerente* servicoGerente = new ContainerGerente();
    ContainerHotel* servicoHotel = new ContainerHotel();

    // PASSO 2: Criar a Interface (Apresentação)
    ControladoraApresentacao app;

    // PASSO 3: Ligar os fios
    app.configurarServicos(servicoGerente);
    app.configurarServicosHotel(servicoHotel); // Agora a função existe no .hpp!

    // PASSO 4: Rodar
    app.executar();

    // PASSO 5: Limpeza
    delete servicoGerente;
    delete servicoHotel;

    return 0;
}
