#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>

class Codigo {
private:
    std::string codigo;

    // Declaraçãoo do método de validação
    void validar(const std::string& codigo);

public:
    // Construtor
    Codigo(std::string codigo);

    // Método set
    void setCodigo(std::string codigo);

    // Método get
    std::string getCodigo();
};

#endif
