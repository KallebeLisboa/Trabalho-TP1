#ifndef CAPACIDADE_HPP
#define CAPACIDADE_HPP

class Capacidade {
private:
    int capacidade; // O atributo que armazena o valor da capacidade

    // Apenas a declaração do método de validação. A implementação ficará no .cpp
    void validar(int capacidade);

public:
    // Declaração do Construtor
    Capacidade(int capacidade);

    // Declaração do método set
    void setCapacidade(int capacidade);

    // Declaração do método get
    // Adicionamos 'const' para indicar que este método não altera o estado do objeto
    int getCapacidade() const;
};

#endif
