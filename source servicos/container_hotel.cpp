#include "ContainerHotel.hpp" // Ajuste o caminho se necessário
#include <stdexcept>
#include <iostream>

// Implementação do Destrutor

ContainerHotel::~ContainerHotel() {
    // Itera sobre o mapa para liberar a memória de cada objeto Hotel alocado.
    // par.second acessa o valor do mapa (o ponteiro Hotel*).
    for (auto const& par : bancoDeHoteis) {
        delete par.second; // Libera a memória dos hotéis alocados na heap
    }
    bancoDeHoteis.clear(); // Limpa as entradas do mapa
}

// Implementação de Criar Hotel

void ContainerHotel::criarHotel(string codigo, string nome, string endereco, string telefone) {
    // 1. Verifica se já existe um hotel com este código (Chave Primária)
    if (bancoDeHoteis.count(codigo) > 0) {
        throw runtime_error("Erro: Ja existe um hotel com este codigo.");
    }

    // 2. Instancia os Domínios.
    // Isso aciona automaticamente as validações (ex: tamanho do código, formato do telefone).
    // Se algum dado for inválido, uma exceção é lançada aqui e o hotel não é criado.
    Codigo domCodigo(codigo);
    Nome domNome(nome);
    Endereco domEndereco(endereco);
    Telefone domTelefone(telefone);

    // 3. Cria a Entidade na memória heap
    Hotel* novoHotel = new Hotel(domNome, domEndereco, domTelefone, domCodigo);

    // 4. Salva no Mapa usando o código como chave
    bancoDeHoteis[codigo] = novoHotel;
    
    cout << " > Sucesso: Hotel '" << nome << "' cadastrado." << endl;
}

// Implementação de Pesquisar

Hotel* ContainerHotel::pesquisarHotel(string codigo) {
    // Verifica se a chave existe no mapa
    if (bancoDeHoteis.count(codigo) > 0) {
        return bancoDeHoteis[codigo];
    }
    return nullptr; // Retorna nulo se não encontrado
}

// Implementação de Listar

map<string, Hotel*> ContainerHotel::listarHoteis() {
    // Retorna o container completo para a camada de apresentação
    return bancoDeHoteis;
}

// Implementação de Atualizar

void ContainerHotel::atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone) {
    // Verifica a existência do registro
    if (bancoDeHoteis.count(codigo) == 0) {
        throw runtime_error("Erro: Hotel nao encontrado.");
    }

    Hotel* hotel = bancoDeHoteis[codigo];

    // Instancia novos domínios para validar os novos dados antes de alterar.
    Nome domNome(novoNome);
    Endereco domEndereco(novoEndereco);
    Telefone domTelefone(novoTelefone);

    // Atualiza os atributos da entidade.
    // Note que o código (PK) não é atualizado, garantindo a integridade referencial.
    hotel->setNome(domNome);
    hotel->setEndereco(domEndereco);
    hotel->setTelefone(domTelefone);
    
    cout << " > Sucesso: Dados do hotel atualizados." << endl;
}

// Implementação de Excluir

void ContainerHotel::excluirHotel(string codigo) {
    if (bancoDeHoteis.count(codigo) > 0) {
        // 1. Libera memória do objeto Hotel
        delete bancoDeHoteis[codigo]; 
        // 2. Remove a entrada do mapa
        bancoDeHoteis.erase(codigo);  
        cout << " > Sucesso: Hotel excluido." << endl;
    } else {
        throw runtime_error("Erro: Hotel nao encontrado para exclusao.");
    }
}