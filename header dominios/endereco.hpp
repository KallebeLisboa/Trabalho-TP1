#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

class Endereco {
private:
    std::string endereco;

    // Declaração do método de validação
    void validar(const std::string& valorEndereco);

public:
    // Construtor
    Endereco(const std::string& valorEndereco);

    // Método set
    void setEndereco(const std::string& valorEndereco);

    // Método get
    std::string getEndereco() const;
};

#endif
