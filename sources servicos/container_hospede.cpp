#include "../header servicos/container_hospede.hpp"
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
    // 1. Verifica se o hóspede existe
    if (bancoDeHospedes.count(email) == 0) {
        throw runtime_error("Erro: Hospede nao encontrado.");
    }

    Hospede* h = bancoDeHospedes[email];

    // 2. Atualiza Nome (Se não for vazio)
    if (!novoNome.empty()) {
        h->setNome(Nome(novoNome));
    }

    // 3. Atualiza Endereço
    if (!novoEndereco.empty()) {
        h->setEndereco(Endereco(novoEndereco));
    }

    // 4. Atualiza Cartão
    if (!novoCartao.empty()) {
        h->setCartao(Cartao(novoCartao));
    }

    cout << " > Sucesso: Dados do hospede atualizados." << endl;
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
