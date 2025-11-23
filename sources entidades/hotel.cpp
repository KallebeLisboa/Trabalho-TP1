#include "header entidades/hotel.hpp"

// Construtor
// Inicializa todos os atributos de domínio usando a lista de inicialização
Hotel::Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo)
    : nome(nome), endereco(endereco), telefone(telefone), codigo(codigo) {}

// Implementação dos Métodos Get
// Retornam a instância da classe de Domínio
Nome Hotel::getNome() const {
    return this->nome;
}

Endereco Hotel::getEndereco() const {
    return this->endereco;
}

Telefone Hotel::getTelefone() const {
    return this->telefone;
}

Codigo Hotel::getCodigo() const {
    return this->codigo;
}

// Implementação dos Métodos Set
// Simplesmente atribui a nova instância do Domínio.
// A validação do formato do valor já ocorreu dentro do construtor
void Hotel::setNome(const Nome& nome) {
    this->nome = nome;
}

void Hotel::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

void Hotel::setTelefone(const Telefone& telefone) {
    this->telefone = telefone;
}

// Observação sobre a Chave Primária:
// O método setCodigo() NÃO está implementado, garantindo que a PK não possa ser alterada após a criação
