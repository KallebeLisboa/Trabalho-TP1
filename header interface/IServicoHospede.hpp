#ifndef ISERVICOHOSPEDE_HPP
#define ISERVICOHOSPEDE_HPP

#include <string>
#include <map>
#include "../header entidades/hospede.hpp"

using namespace std;

class IServicoHospede {
public:
    virtual ~IServicoHospede() {}

    virtual void criarHospede(string nome, string email, string endereco, string cartao) = 0;
    virtual Hospede* pesquisarHospede(string email) = 0;
    virtual map<string, Hospede*> listarHospedes() = 0;

    virtual void atualizarHospede(string email, string novoNome, string novoEndereco, string novoCartao) = 0;

    virtual void excluirHospede(string email) = 0;
};

#endif
