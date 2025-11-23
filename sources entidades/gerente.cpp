#include "header entidades/gerente.hpp"
#include <stdexcept> // Para lidar com possíveis exceções das classes de Domínio

// Construtor
// O Gerente recebe todos os parâmetros necessários.
// 1. Chama o construtor da classe base (Pessoa) passando (nome, email).
// 2. Inicializa seus próprios atributos (ramal, senha).
Gerente::Gerente(const Nome& nome, const Email& email, const Ramal& ramal, const Senha& senha)
    : Pessoa(nome, email), // CHAMA O CONSTRUTOR DA CLASSE MÃE (Pessoa)
      ramal(ramal),        // Inicializa o atributo Ramal
      senha(senha)         // Inicializa o atributo Senha
{
    // O corpo do construtor fica vazio, pois toda a inicialização e
    // validação (via objetos de Domínio) já foram feitas na lista de inicialização.
}

// Implementação do Método Get para Ramal
Ramal Gerente::getRamal() const {
    return this->ramal;
}

// Implementação do Método Get para Senha
Senha Gerente::getSenha() const {
    return this->senha;
}

// Implementação do Método Set para Ramal
void Gerente::setRamal(const Ramal& ramal) {
    this->ramal = ramal;
}

// Implementação do Método Set para Senha
void Gerente::setSenha(const Senha& senha) {
    this->senha = senha;
}
