#include "header servicos\container_quarto.hpp"
#include <stdexcept>
#include <iostream>

ContainerQuarto::~ContainerQuarto() {
    for (auto& par : bancoDeQuartos) delete par.second;
    bancoDeQuartos.clear();
}

void ContainerQuarto::criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal) {
    string chave = gerarChave(codigoHotel, numero);

    if (bancoDeQuartos.count(chave) > 0) {
        throw runtime_error("Erro: Quarto ja existe neste hotel.");
    }

    Quarto* novoQuarto = new Quarto(
        Codigo(codigoHotel),
        Numero(numero),
        Capacidade(capacidade),
        Dinheiro(valorDiaria),
        Ramal(ramal)
    );

    bancoDeQuartos[chave] = novoQuarto;
    cout << " > Sucesso: Quarto criado." << endl;
}

map<string, Quarto*> ContainerQuarto::listarQuartosDoHotel(string codigoHotel) {
    map<string, Quarto*> filtro;
    // Retorna só os do hotel específico
    for (auto const& par : bancoDeQuartos) {
        if (par.second->getCodigoHotel().getCodigo() == codigoHotel) {
            filtro[par.first] = par.second;
        }
    }
    return filtro;
}

void ContainerQuarto::atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal) {
    string chave = gerarChave(codigoHotel, numero);

    if (bancoDeQuartos.count(chave) == 0) {
        throw runtime_error("Erro: Quarto nao encontrado.");
    }

    Quarto* q = bancoDeQuartos[chave];

    // 1. Capacidade (Só atualiza se for diferente de -1)
    if (novaCapacidade != -1) {
        q->setCapacidade(Capacidade(novaCapacidade));
    }

    // 2. Valor Diária (Só atualiza se for diferente de -1)
    if (novoValor != -1.0) {
        q->setDiaria(Dinheiro(novoValor));
    }

    // 3. Ramal (Só atualiza se não for vazio)
    if (!novoRamal.empty()) {
        q->setRamal(Ramal(novoRamal));
    }

    cout << " > Sucesso: Dados do quarto atualizados." << endl;
}

void ContainerQuarto::excluirQuarto(string codigoHotel, string numero) {
    string chave = gerarChave(codigoHotel, numero);
    if (bancoDeQuartos.count(chave) > 0) {
        delete bancoDeQuartos[chave];
        bancoDeQuartos.erase(chave);
        cout << " > Sucesso: Quarto removido." << endl;
    } else {
        throw runtime_error("Erro: Quarto nao encontrado.");
    }
}

// Implementação da busca
Quarto* ContainerQuarto::pesquisarQuarto(string codigoHotel, string numero) {
    // Recria a chave composta
    string chave = gerarChave(codigoHotel, numero);

    // Verifica se existe no mapa
    if (bancoDeQuartos.count(chave) > 0) {
        return bancoDeQuartos[chave];
    }
    return nullptr; // Retorna nulo se não achar
}
