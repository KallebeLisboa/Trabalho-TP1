#ifndef CONTAINER_GERENTE_HPP
#define CONTAINER_GERENTE_HPP

#include <map>
#include <string>
#include "header entidades/gerente.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/senha.hpp"
#include "header dominios/ramal.hpp"

using namespace std;

class ContainerGerente {
private:
    // Chave: Email (Login)
    map<string, Gerente*> bancoDeGerentes;

public:
    ~ContainerGerente();

    void criarGerente(string nome, string email, string ramal, string senha);
    
    bool autenticar(string email, string senha);

    Gerente* pesquisarGerente(string email);
    void atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha);
    void excluirGerente(string email);

    map<string, Gerente*> listarGerentes();
};

#endif