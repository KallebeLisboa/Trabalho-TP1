#ifndef NOME_HPP
#define NOME_HPP

#include <string>

class Nome {
private:
    std::string nome;

    // Declaração do método de validação
    void validar(const std::string& valorNome);

public:
    // Construtor
    Nome(const std::string& valorNome);

    // Método set
    void setNome(const std::string& valorNome);

    // Método get
    std::string getNome() const;
};

#endif
