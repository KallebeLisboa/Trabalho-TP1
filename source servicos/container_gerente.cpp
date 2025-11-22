#include "ContainerGerente.hpp" // Ajuste o caminho se necessário
#include <stdexcept>
#include <iostream>

// Implementação do Destrutor

ContainerGerente::~ContainerGerente() {
    // Como armazenamos ponteiros (Gerente*), precisamos deletar cada objeto
    // manualmente para evitar vazamento de memória (memory leak) antes de limpar o mapa.
    for (auto& par : bancoDeGerentes) {
        delete par.second; // Deleta o objeto Gerente apontado
    }
    bancoDeGerentes.clear(); // Limpa as entradas do mapa
}

// Implementação de Criar Gerente

void ContainerGerente::criarGerente(string nome, string email, string ramal, string senha) {
    // Verifica se já existe um gerente com esse email (Chave Primária)
    if (bancoDeGerentes.count(email) > 0) {
        throw runtime_error("Erro: Email ja cadastrado.");
    }

    // Instanciação com validação automática dos domínios.
    // Se algum dado for inválido (ex: senha fraca), o construtor do domínio lança exceção
    // e o processo é interrompido antes de criar o 'new Gerente'.
    Gerente* novoGerente = new Gerente(
        Nome(nome),
        Email(email),
        Ramal(ramal),
        Senha(senha)
    );

    // Armazena no mapa e exibe sucesso
    bancoDeGerentes[email] = novoGerente;
    cout << " > Sucesso: Gerente cadastrado." << endl;
}

// Implementação de Autenticar

bool ContainerGerente::autenticar(string email, string senha) {
    // 1. Verifica se o email existe no banco
    if (bancoDeGerentes.count(email) == 0) {
        return false; 
    }

    // 2. Recupera o ponteiro para o gerente
    Gerente* g = bancoDeGerentes[email];

    // 3. Compara a senha armazenada com a senha fornecida
    // g->getSenha() retorna o objeto Domínio Senha.
    // .getSenha() do domínio retorna a string pura.
    if (g->getSenha().getSenha() == senha) {
        return true;
    }
    
    return false;
}

// Implementação de Pesquisar

Gerente* ContainerGerente::pesquisarGerente(string email) {
    // Retorna o ponteiro se encontrar, ou nullptr se não existir.
    if (bancoDeGerentes.count(email) > 0) {
        return bancoDeGerentes[email];
    }
    return nullptr;
}

// Implementação de Atualizar

void ContainerGerente::atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha) {
    // Verifica se o gerente existe antes de tentar atualizar
    if (bancoDeGerentes.count(email) == 0) {
        throw runtime_error("Erro: Gerente nao encontrado.");
    }

    Gerente* g = bancoDeGerentes[email];
    
    // Ao instanciar novos objetos de domínio (Nome, Ramal, Senha),
    // a validação ocorre automaticamente. Se falhar, lança exceção e não atualiza.
    g->setNome(Nome(novoNome));
    g->setRamal(Ramal(novoRamal));
    g->setSenha(Senha(novaSenha));

    cout << " > Sucesso: Dados do gerente atualizados." << endl;
}

// Implementação de Excluir

void ContainerGerente::excluirGerente(string email) {
    if (bancoDeGerentes.count(email) > 0) {
        // 1. Libera a memória do objeto
        delete bancoDeGerentes[email];
        // 2. Remove a entrada do mapa
        bancoDeGerentes.erase(email);
        cout << " > Sucesso: Conta de gerente excluida." << endl;
    } else {
        throw runtime_error("Erro: Gerente nao encontrado.");
    }
}

// Implementação de Listar

map<string, Gerente*> ContainerGerente::listarGerentes() {
    // Retorna o mapa completo para que a camada de apresentação possa iterar e exibir.
    return bancoDeGerentes;
}