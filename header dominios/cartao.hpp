#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>

class Cartao {
private:
    std::string cartao;

    // Métodos privados auxiliares para o Algoritmo de Luhn
    int pegarDigito(int numero) const;
    int somarDigitosPares(const std::string& numeroCartao) const;
    int somarDigitosImpares(const std::string& numeroCartao) const;

    // Método de validação principal
    void validar(const std::string& numeroCartao);

public:
    // Construtor
    Cartao(const std::string& numeroCartao);

    // Método set
    void setCartao(const std::string& numeroCartao);

    // Método get
    std::string getCartao() const;
};

#endif
