#ifndef ISERVICOUSUARIO_HPP
#define ISERVICOUSUARIO_HPP

#include <string>
#include "../header entidades/gerente.hpp"

using namespace std;

class IServicoUsuario {
public:
    virtual ~IServicoUsuario() {}

    // Métodos virtuais puros (= 0)
    virtual void criarGerente(string nome, string email, string ramal, string senha) = 0;
    virtual bool autenticar(string email, string senha) = 0;

    virtual Gerente* pesquisarGerente(string email) = 0;

    virtual void atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha) = 0;
    virtual void excluirGerente(string email) = 0;
};

#endif // ISERVICOUSUARIO_HPP
