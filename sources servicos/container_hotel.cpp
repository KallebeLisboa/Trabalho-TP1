#include "header servicos\container_hotel.hpp"
#include <stdexcept>

ContainerHotel::~ContainerHotel() {
    for (auto const& par : bancoDeHoteis) {
        delete par.second; // Libera a memória dos hotéis alocados
    }
    bancoDeHoteis.clear();
}

void ContainerHotel::criarHotel(string codigo, string nome, string endereco, string telefone) {
    // 1. Verifica se já existe
    if (bancoDeHoteis.count(codigo) > 0) {
        throw runtime_error("Erro: Ja existe um hotel com este codigo.");
    }

    // 2. Instancia os Domínios
    Codigo domCodigo(codigo);
    Nome domNome(nome);
    Endereco domEndereco(endereco);
    Telefone domTelefone(telefone);

    // 3. Cria a Entidade
    Hotel* novoHotel = new Hotel(domNome, domEndereco, domTelefone, domCodigo);

    // 4. Salva no Mapa
    bancoDeHoteis[codigo] = novoHotel;
    cout << " > Sucesso: Hotel '" << nome << "' cadastrado." << endl;
}

Hotel* ContainerHotel::pesquisarHotel(string codigo) {
    if (bancoDeHoteis.count(codigo) > 0) {
        return bancoDeHoteis[codigo];
    }
    return nullptr;
}

map<string, Hotel*> ContainerHotel::listarHoteis() {
    return bancoDeHoteis;
}

void ContainerHotel::atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone) {
    if (bancoDeHoteis.count(codigo) == 0) {
        throw runtime_error("Erro: Hotel nao encontrado.");
    }

    Hotel* hotel = bancoDeHoteis[codigo];

    // Atualiza apenas se as strings não estiverem vazias
    // Instancia novos domínios para validar os novos dados
    Nome domNome(novoNome);
    Endereco domEndereco(novoEndereco);
    Telefone domTelefone(novoTelefone);

    hotel->setNome(domNome);
    hotel->setEndereco(domEndereco);
    hotel->setTelefone(domTelefone);
    
    cout << " > Sucesso: Dados do hotel atualizados." << endl;
}

void ContainerHotel::excluirHotel(string codigo) {
    if (bancoDeHoteis.count(codigo) > 0) {
        delete bancoDeHoteis[codigo]; // Libera memória
        bancoDeHoteis.erase(codigo);  // Remove do mapa
        cout << " > Sucesso: Hotel excluido." << endl;
    } else {
        throw runtime_error("Erro: Hotel nao encontrado para exclusao.");
    }
}