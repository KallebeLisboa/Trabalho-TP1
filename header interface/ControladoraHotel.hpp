#ifndef CONTROLADORAHOTEL_HPP_INCLUDED
#define CONTROLADORAHOTEL_HPP_INCLUDED

#include <iostream>
#include <string>
#include "IServicoHotel.hpp"

using namespace std;

class ControladoraHotel {
private:
    IServicoHotel* servicoHotel;

    void exibirOpcoes();
    void criarHotel();
    void lerHotel();
    void editarHotel();
    void excluirHotel();
    void listarHoteis();

public:
    // Adicione o Setter
    void setServicoHotel(IServicoHotel* s) { servicoHotel = s; }

    void executar();
};

#endif // CONTROLADORAHOTEL_HPP_INCLUDED
