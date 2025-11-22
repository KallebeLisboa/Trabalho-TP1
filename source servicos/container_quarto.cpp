#include "ContainerQuarto.hpp" // Ajuste o caminho se necessário
#include <stdexcept>
#include <iostream>


// Implementação do Destrutor

ContainerQuarto::~ContainerQuarto() {
    // Itera sobre o mapa de quartos para liberar a memória alocada dinamicamente.
    for (auto& par : bancoDeQuartos) {
        delete par.second; // Deleta o objeto Quarto
    }
    bancoDeQuartos.clear(); // Limpa o container
}


// Implementação de Criar Quarto

void ContainerQuarto::criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal) {
    // Gera a chave composta (Ex: "H01_104") para garantir unicidade no mapa.
    string chave = gerarChave(codigoHotel, numero);

    // Verifica se o quarto já existe neste hotel específico.
    if (bancoDeQuartos.count(chave) > 0) {
        throw runtime_error("Erro: Quarto ja existe neste hotel.");
    }

    // Instancia o objeto Quarto. 
    // Os construtores dos domínios (Codigo, Numero, Capacidade, etc.) são chamados aqui.
    // Se qualquer valor for inválido, uma exceção será lançada e o fluxo para.
    Quarto* novoQuarto = new Quarto(
        Codigo(codigoHotel),
        Numero(numero),
        Capacidade(capacidade),
        Dinheiro(valorDiaria),
        Ramal(ramal)
    );

    // Armazena no mapa usando a chave composta.
    bancoDeQua
    
// Implementação de Listar Quartos de um Hotel

map<string, Quarto*> ContainerQuarto::listarQuartosDoHotel(string codigoHotel) {
    map<string, Quarto*> filtro;
    
    // Como o mapa contém quartos de TODOS os hotéis, precisamos iterar sobre ele
    // e filtrar apenas aqueles cujo código do hotel coincide com o solicitado.
    for (auto const& par : bancoDeQuartos) {
        // par.second é o ponteiro para o Quarto.
        // Acessamos o domínio CodigoHotel e depois a string do código.
        if (par.second->getCodigoHotel().getCodigo() == codigoHotel) {
            filtro[par.first] = par.second;
        }
    }
    return filtro;
}

// Implementação de Atualizar

void ContainerQuarto::atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal) {
    // Reconstrói a chave composta para busca.
    string chave = gerarChave(codigoHotel, numero);
    
    // Verifica se o quarto existe.
    if (bancoDeQuartos.count(chave) == 0) {
        throw runtime_error("Erro: Quarto nao encontrado.");
    }

    Quarto* q = bancoDeQuartos[chave];
    
    // Atualiza os atributos mutáveis, validando através dos construtores de Domínio.
    q->setCapacidade(Capacidade(novaCapacidade));
    q->setDiaria(Dinheiro(novoValor));
    q->setRamal(Ramal(novoRamal));
    
    cout << " > Sucesso: Quarto atualizado." << endl;
}

// Implementação de Excluir

void ContainerQuarto::excluirQuarto(string codigoHotel, string numero) {
    string chave = gerarChave(codigoHotel, numero);
    
    if (bancoDeQuartos.count(chave) > 0) {
        // 1. Libera memória
        delete bancoDeQuartos[chave];
        // 2. Remove do mapa
        bancoDeQuartos.erase(chave);
        cout << " > Sucesso: Quarto removido." << endl;
    } else {
        throw runtime_error("Erro: Quarto nao encontrado.");
    }
}