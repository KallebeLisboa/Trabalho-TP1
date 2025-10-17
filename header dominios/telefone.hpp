#ifndef TELEFONE_HPP
#define TELEFONE_HPP

#include <string>

class Telefone {
private:
    std::string telefone;

    // Declaração do método de validação
    void validar(const std::string& valorTelefone);

public:
    // Construtor
    Telefone(const std::string& valorTelefone);

    // Método set
    void setTelefone(const std::string& valorTelefone);

    // Método get
    std::string getTelefone() const;
};

#endif
