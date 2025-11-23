#ifndef RAMAL_HPP
#define RAMAL_HPP

#include <string>

class Ramal {
private:
    std::string ramal;

    // Declaração do método de validação
    void validar(std::string const &ramal);

public:
    // Construtor
    Ramal(std::string ramal);
    // Método set
    void setRamal(std::string ramal);

    // Método get
    std::string getRamal();
};

#endif
