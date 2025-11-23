#ifndef ISERVICOUSUARIO_HPP
#define ISERVICOUSUARIO_HPP

// 1. Includes fundamentais
#include <string>

// 2. Include da Entidade Gerente (Para o compilador saber o que é "Gerente")
#include "../header entidades/gerente.hpp"

using namespace std;

// Interface que define quais métodos o Container deve ter
class IServicoUsuario {
public:
    virtual ~IServicoUsuario() {}

    // Métodos virtuais puros (= 0)
    virtual void criarGerente(string nome, string email, string ramal, string senha) = 0;
    virtual bool autenticar(string email, string senha) = 0;

    // Aqui usamos o tipo 'Gerente*', por isso o include acima é obrigatório
    virtual Gerente* pesquisarGerente(string email) = 0;

    virtual void atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha) = 0;
    virtual void excluirGerente(string email) = 0;
};

#endif // ISERVICOUSUARIO_HPP
