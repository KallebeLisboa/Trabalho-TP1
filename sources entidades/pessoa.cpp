#include "Pessoa.hpp"

// Construtor
Pessoa::Pessoa(const Nome& nome, const Email& email)
    : nome(nome), email(email) {}

// Implementação do Método Get
Nome Pessoa::getNome() const {
    return this->nome;
}
Email Pessoa::getEmail() const {
    return this->email;
}

// Implementação do Método Set
void Pessoa::setNome(const Nome& nome) {
    this->nome = nome;
}