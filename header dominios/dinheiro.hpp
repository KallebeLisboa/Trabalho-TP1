#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

class Dinheiro {
private:

    int dinheiro; // Armazenado em centavos. R$1.99 vira 199 centavos

    // Valida o valor em centavos.
    void validar(int const &dinheiro);

public:
    // Construtor que aceita um valor double (ex: 19.99)
    Dinheiro(double dinheiro);

    // Método set que também aceita um double
    void setDinheiro(double dinheiro);

    // Método get que retorna o valor como double
    double getDinheiro();
};

#endif
