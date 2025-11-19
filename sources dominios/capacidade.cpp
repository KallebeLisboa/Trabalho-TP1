#include "header dominios/capacidade.hpp" // Inclui a declaração da classe para poder implementar seus métodos
#include <stdexcept>      // Necessário para usar a exceção std::invalid_argument

// Implementação do método de validação
void Capacidade::validar(int const &capacidade) {
    if (capacidade < 1 || capacidade > 4) {
        throw std::invalid_argument("Capacidade invalida. Deve ser 1, 2, 3 ou 4.");
    }
}
// Implementação do Construtor
Capacidade::Capacidade(int capacidade){
    validar(capacidade);
    this->capacidade = capacidade;
}

// Implementação do método set
void Capacidade::setCapacidade(int capacidade) {
    validar(capacidade);
    this->capacidade = capacidade;
}

// Implementação do método get
int Capacidade::getCapacidade() {
    return this->capacidade;
}
