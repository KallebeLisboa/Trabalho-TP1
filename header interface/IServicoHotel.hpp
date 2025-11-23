#ifndef ISERVICOHOTEL_HPP
#define ISERVICOHOTEL_HPP

#include <string>
#include <map> // <--- IMPORTANTE: Necessário para usar o map
#include "../header entidades/hotel.hpp"

using namespace std;

class IServicoHotel {
public:
    virtual ~IServicoHotel() {}

    // Métodos virtuais puros (= 0)
    virtual void criarHotel(string codigo, string nome, string endereco, string telefone) = 0;

    virtual Hotel* pesquisarHotel(string codigo) = 0;

    // --- NOVO MÉTODO ---
    virtual map<string, Hotel*> listarHoteis() = 0;

    virtual void atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone) = 0;
    virtual void excluirHotel(string codigo) = 0;
};

#endif // ISERVICOHOTEL_HPP
