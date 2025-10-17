#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <string>

class Numero {
private:
    std::string numero;

    // Declaração do método de validação
    void validar(const std::string& valorNumero);

public:
    // Construtor
    Numero(const std::string& valorNumero);

    // Método set
    void setNumero(const std::string& valorNumero);

    // Método get
    std::string getNumero() const;
};

#endif
