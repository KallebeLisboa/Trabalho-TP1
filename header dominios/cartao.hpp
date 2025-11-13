#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>
#include <stdexcept>
#include <cctype> // Para usar isdigit

class Cartao {
private:
    std::string cartao;

    // Funções auxiliares (Implementadas no .cpp)
    int pegarDigito(const int numero);
    int somarDigitosPares(const std::string cartao);
    int somarDigitosImpares(const std::string cartao);
    void validar(std::string const &cartao);

public:
    // Construtor e Getters/Setters (Implementados no .cpp)
    Cartao(std::string cartao);
    void setCartao(std::string cartao);
    std::string getCartao();
};

#endif // CARTAO_HPP