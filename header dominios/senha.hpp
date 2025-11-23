#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>

class Senha {
private:
    std::string senha;

    // Declaração do método de validação
    void validar(std::string const &senha);

public:
    // Construtor
    Senha(std::string senha);
    // Método set
    void setSenha(std::string senha);

    // Método get
    std::string getSenha();
};

#endif