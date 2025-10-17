#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>

class Senha {
private:
    std::string senha;

    // Declaração do método de validação
    void validar(const std::string& valorSenha);

public:
    // Construtor
    Senha(const std::string& valorSenha);

    // Método set
    void setSenha(const std::string& valorSenha);

    // Método get
    std::string getSenha() const;
};

#endif