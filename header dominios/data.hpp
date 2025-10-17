#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
    std::string data; // Armazena a data no formato "dia-mês-ano"

    // Método auxiliar para verificar se um ano é bissexto
    bool anoBissexto(int ano) const;

    // Método principal de validação
    void validar(const std::string& dataCompleta);

public:
    // Construtor
    Data(const std::string& dataCompleta);

    // Método set
    void setData(const std::string& dataCompleta);

    // Método get
    std::string getData() const;
};

#endif // DATA_HPP
