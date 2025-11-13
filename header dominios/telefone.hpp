#ifndef TELEFONE_HPP
#define TELEFONE_HPP

#include <string>

class Telefone {
private:
    std::string telefone;

    // Declaração do método de validação
    void validar(std::string const &telefone);

public:
    // Construtor
    Telefone(std::string telefone);
    // Método set
    void setTelefone(std::string telefone);

    // Método get
    std::string getTelefone();
};

#endif
