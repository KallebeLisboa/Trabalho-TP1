#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

class Dinheiro {
private:
    // O valor é armazenado como um inteiro de centavos para evitar erros de precisão com double.
    int centavos;

    // Valida o valor em centavos.
    void validar(int valorEmCentavos);

public:
    // Construtor que aceita um valor double (ex: 19.99)
    Dinheiro(double valor);

    // Método set que também aceita um double
    void setDinheiro(double valor);

    // Método get que retorna o valor como double
    double getDinheiro() const;
};

#endif
