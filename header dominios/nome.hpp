#ifndef NOME_HPP
#define NOME_HPP

#include <string>

class Nome {
private:
    std::string nome;

    // Declaração do método de validação
    void validar(std::string const &nome);

public:
    // Construtor
    Nome(std::string nome);

    // Método set
    void setNome(std::string nome);

    // Método get
    std::string getNome();
};

#endif
