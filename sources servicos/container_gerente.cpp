// container_gerente.cpp
#include "header servicos\container_gerente.hpp"
#include <stdexcept>
#include <iostream>

ContainerGerente::~ContainerGerente() {
    for (auto& par : bancoDeGerentes) delete par.second;
    bancoDeGerentes.clear();
}

void ContainerGerente::criarGerente(string nome, string email, string ramal, string senha) {
    if (bancoDeGerentes.count(email) > 0) {
        throw runtime_error("Erro: Email ja cadastrado.");
    }

    // Instanciação com validação automática dos domínios
    Gerente* novoGerente = new Gerente(
        Nome(nome),
        Email(email),
        Ramal(ramal),
        Senha(senha)
    );

    bancoDeGerentes[email] = novoGerente;
    cout << " > Sucesso: Gerente cadastrado." << endl;
}

bool ContainerGerente::autenticar(string email, string senha) {
    // 1. Verifica se o email existe
    if (bancoDeGerentes.count(email) == 0) {
        return false; 
    }

    // 2. Recupera o gerente
    Gerente* g = bancoDeGerentes[email];

    // 3. Compara a senha armazenada com a senha fornecida
    if (g->getSenha().getSenha() == senha) {
        return true;
    }
    
    return false;
}

Gerente* ContainerGerente::pesquisarGerente(string email) {
    if (bancoDeGerentes.count(email) > 0) return bancoDeGerentes[email];
    return nullptr;
}

void ContainerGerente::atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha) {
    if (bancoDeGerentes.count(email) == 0) throw runtime_error("Erro: Gerente nao encontrado.");

    Gerente* g = bancoDeGerentes[email];
    
    g->setNome(Nome(novoNome));
    g->setRamal(Ramal(novoRamal));
    g->setSenha(Senha(novaSenha));

    cout << " > Sucesso: Dados do gerente atualizados." << endl;
}

void ContainerGerente::excluirGerente(string email) {
    if (bancoDeGerentes.count(email) > 0) {
        delete bancoDeGerentes[email];
        bancoDeGerentes.erase(email);
        cout << " > Sucesso: Conta de gerente excluida." << endl;
    } else {
        throw runtime_error("Erro: Gerente nao encontrado.");
    }
}

map<string, Gerente*> ContainerGerente::listarGerentes() {
    return bancoDeGerentes;
}