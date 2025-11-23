#ifndef CAPACIDADE_HPP
#define CAPACIDADE_HPP

class Capacidade {
private:
    int capacidade; // O atributo que armazena o valor da capacidade

    // Apenas a declaração do método de validação. A implementação ficará no .cpp
    void validar(int const &capacidade);

public:
    // Declaração do Construtor
    Capacidade(int capacidade);

    // Declaração do método set
    void setCapacidade(int capacidade);

    // Declaração do método get

    int getCapacidade();
};

#endif
