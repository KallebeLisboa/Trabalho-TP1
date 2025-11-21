#include "header dominios/capacidade.hpp" 
#include <stdexcept>      // Necessário para lançar exceções

// Implementação do método de validação

void Capacidade::validar(int const &capacidade) {
    // Regra de Negócio: A capacidade do quarto deve ser 1, 2, 3 ou 4.
    // Qualquer valor fora deste intervalo é considerado inválido.
    if (capacidade < 1 || capacidade > 4) {
        throw std::invalid_argument("Capacidade invalida. Deve ser 1, 2, 3 ou 4.");
    }
}


// Implementação do Construtor

Capacidade::Capacidade(int capacidade){
    // Valida o valor antes de atribuir. Se falhar, o objeto não é criado.
    validar(capacidade);
    this->capacidade = capacidade;
}


// Implementação do método set

void Capacidade::setCapacidade(int capacidade) {
    // Valida o novo valor antes de modificar o estado do objeto.
    validar(capacidade);
    this->capacidade = capacidade;
}

// Implementação do método get

int Capacidade::getCapacidade() {
    return this->capacidade;
}