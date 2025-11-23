#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

class Endereco {
private:
    std::string endereco;

    // Declaração do método de validação
    void validar(std::string const &endereco);

public:
    // Construtor
    Endereco(std::string endereco);

    // Método set
    void setEndereco(std::string endereco);

    // Método get
    std::string getEndereco();
};

#endif
