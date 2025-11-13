#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
    std::string data; // Armazena a data no formato "dia-mês-ano"

    // Método auxiliar para verificar se um ano é bissexto
    bool anoBissexto(int ano);

    // Método principal de validação
    void validar(std::string const &data);

public:
    // Construtor
    Data(std::string data);

    // Método set
    void setData(std::string data);

    // Método get
    std::string getData();
};

#endif // DATA_HPP
