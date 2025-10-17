#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>

class Codigo {
private:
    std::string codigo;

    // Declaraçãoo do método de validação
    void validar(const std::string& valorCodigo);

public:
    // Construtor
    Codigo(const std::string& valorCodigo);

    // Método set
    void setCodigo(const std::string& valorCodigo);

    // Método get
    std::string getCodigo() const;
};

#endif
