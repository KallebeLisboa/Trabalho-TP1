#include "ContainerHospede.hpp" // Ajuste o caminho se necessário
#include <stdexcept>
#include <iostream>

// Implementação do Destrutor

ContainerHospede::~ContainerHospede() {
    // Itera sobre todo o mapa para deletar os objetos Hospede alocados dinamicamente.
    // Isso previne vazamento de memória ao encerrar o container.
    for (auto& par : bancoDeHospedes) {
        delete par.second; 
    }
    bancoDeHospedes.clear(); // Limpa as referências do mapa.
}

// Implementação de Criar Hospede

void ContainerHospede::criarHospede(string nome, string email, string endereco, string cartao) {
    // Verifica a restrição de unicidade da Chave Primária (Email).
    if (bancoDeHospedes.count(email) > 0) {
        throw runtime_error("Erro: Ja existe um hospede com este e-mail.");
    }

    // Instancia objetos de Domínio. 
    // Se algum formato for inválido (ex: cartão errado), o construtor do domínio
    // lançará uma exceção e o método será interrompido aqui, garantindo a integridade.
    Nome domNome(nome);
    Email domEmail(email);
    Endereco domEndereco(endereco);
    Cartao domCartao(cartao);

    // Cria o objeto Entidade e o armazena no mapa.
    Hospede* novoHospede = new Hospede(domNome, domEmail, domEndereco, domCartao);
    bancoDeHospedes[email] = novoHospede;
    
    cout << " > Sucesso: Hospede cadastrado." << endl;
}

// Implementação de Pesquisar

Hospede* ContainerHospede::pesquisarHospede(string email) {
    // Verifica se a chave existe antes de retornar.
    if (bancoDeHospedes.count(email) > 0) {
        return bancoDeHospedes[email];
    }
    // Retorna nulo se o hóspede não for encontrado.
    return nullptr;
}

// Implementação de Listar

map<string, Hospede*> ContainerHospede::listarHospedes() {
    // Retorna o banco de dados completo (mapa) para a camada de apresentação.
    return bancoDeHospedes;
}

// Implementação de Atualizar

void ContainerHospede::atualizarHospede(string email, string novoNome, string novoEndereco, string novoCartao) {
    // Verifica se o registro existe.
    if (bancoDeHospedes.count(email) == 0) {
        throw runtime_error("Erro: Hospede nao encontrado.");
    }

    Hospede* hospede = bancoDeHospedes[email];
    
    // Atualiza os atributos individualmente.
    // As exceções de validação dos domínios (Nome, Endereco, Cartao) são propagadas automaticamente.
    hospede->setNome(Nome(novoNome));
    hospede->setEndereco(Endereco(novoEndereco));
    hospede->setCartao(Cartao(novoCartao));

    cout << " > Sucesso: Hospede atualizado." << endl;
}

// Implementação de Excluir

void ContainerHospede::excluirHospede(string email) {
    // Verifica se o registro existe antes de tentar excluir.
    if (bancoDeHospedes.count(email) > 0) {
        // 1. Libera a memória heap ocupada pelo objeto.
        delete bancoDeHospedes[email];
        // 2. Remove a entrada (chave/valor) do mapa.
        bancoDeHospedes.erase(email);
        cout << " > Sucesso: Hospede excluido." << endl;
    } else {
        throw runtime_error("Erro: Hospede nao encontrado.");
    }
}