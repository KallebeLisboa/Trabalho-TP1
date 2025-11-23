#ifndef CONTAINER_HOSPEDE_HPP
#define CONTAINER_HOSPEDE_HPP

#include <map>
#include <string>
#include "header entidades/hospede.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/cartao.hpp"

using namespace std;

class ContainerHospede {
private:
    map<string, Hospede*> bancoDeHospedes; // Chave: Email

public:
    ~ContainerHospede();

    void criarHospede(string nome, string email, string endereco, string cartao);
    Hospede* pesquisarHospede(string email);
    map<string, Hospede*> listarHospedes();
    void atualizarHospede(string email, string novoNome, string novoEndereco, string novoCartao);
    void excluirHospede(string email);
};

#endif