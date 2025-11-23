#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <string>

class Numero {
private:
    std::string numero;

    // Declaração do método de validação
    void validar(std::string const &numero);

public:
    // Construtor
    Numero(std::string numero);
    // Método set
    void setNumero(std::string numero);

    // Método get
    std::string getNumero();
};

#endif
