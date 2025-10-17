#ifndef RAMAL_HPP
#define RAMAL_HPP

#include <string>

class Ramal {
private:
    std::string ramal;

    // Declaração do método de validação
    void validar(const std::string& valorRamal);

public:
    // Construtor
    Ramal(const std::string& valorRamal);

    // Método set
    void setRamal(const std::string& valorRamal);

    // Método get
    std::string getRamal() const;
};

#endif
