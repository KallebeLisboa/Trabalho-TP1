#include "Hospede.hpp"
#include <stdexcept> // Para lidar com possíveis exceções das classes de Domínio

// Construtor
// O Hospede recebe todos os parâmetros necessários.
// 1. Chama o construtor da classe base (Pessoa) passando (nome, email).
// 2. Inicializa seus próprios atributos (endereco, cartao).
Hospede::Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao)
    : Pessoa(nome, email), // CHAMA O CONSTRUTOR DA CLASSE MÃE (Pessoa)
      endereco(endereco),        // Inicializa o atributo Endereco
      cartao(cartao)         // Inicializa o atributo Cartao
{
    // O corpo do construtor fica vazio, pois toda a inicialização e 
    // validação (via objetos de Domínio) já foram feitas na lista de inicialização.
}

// Implementação do Método Get para Endereco
Endereco Hospede::getEndereco() const {
    return this->endereco;
}

// Implementação do Método Get para Cartao
Cartao Hospede::getCartao() const {
    return this->cartao;
}

// Implementação do Método Set para Endereco
void Hospede::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

// Implementação do Método Set para Cartao
void Hospede::setCartao(const Cartao& cartao) {
    this->cartao = cartao;
}