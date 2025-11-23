#include "header servicos\container_hospede.hpp"
#include <stdexcept>
#include <iostream>

ContainerHospede::~ContainerHospede() {
    for (auto& par : bancoDeHospedes) delete par.second;
    bancoDeHospedes.clear();
}

void ContainerHospede::criarHospede(string nome, string email, string endereco, string cartao) {
    if (bancoDeHospedes.count(email) > 0) {
        throw runtime_error("Erro: Ja existe um hospede com este e-mail.");
    }

    // Instancia Domínios (lança exceção se inválido)
    Nome domNome(nome);
    Email domEmail(email);
    Endereco domEndereco(endereco);
    Cartao domCartao(cartao);

    Hospede* novoHospede = new Hospede(domNome, domEmail, domEndereco, domCartao);
    bancoDeHospedes[email] = novoHospede;
    
    cout << " > Sucesso: Hospede cadastrado." << endl;
}

Hospede* ContainerHospede::pesquisarHospede(string email) {
    if (bancoDeHospedes.count(email) > 0) return bancoDeHospedes[email];
    return nullptr;
}

map<string, Hospede*> ContainerHospede::listarHospedes() {
    return bancoDeHospedes;
}

void ContainerHospede::atualizarHospede(string email, string novoNome, string novoEndereco, string novoCartao) {
    if (bancoDeHospedes.count(email) == 0) throw runtime_error("Erro: Hospede nao encontrado.");

    Hospede* hospede = bancoDeHospedes[email];
    
    hospede->setNome(Nome(novoNome));
    hospede->setEndereco(Endereco(novoEndereco));
    hospede->setCartao(Cartao(novoCartao));

    cout << " > Sucesso: Hospede atualizado." << endl;
}

void ContainerHospede::excluirHospede(string email) {
    if (bancoDeHospedes.count(email) > 0) {
        delete bancoDeHospedes[email];
        bancoDeHospedes.erase(email);
        cout << " > Sucesso: Hospede excluido." << endl;
    } else {
        throw runtime_error("Erro: Hospede nao encontrado.");
    }
}