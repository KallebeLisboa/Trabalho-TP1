#ifndef RAMAL_HPP
#define RAMAL_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

    ///
    /// @brief Representa o domínio de Ramal telefônico.
    ///
    /// @details Esta classe armazena e valida uma string numérica que representa um ramal.
    /// Regras de validação:
    /// 1. O valor deve representar um número inteiro.
    /// 2. O intervalo válido é de 00 a 50.
///
class Ramal {
private:
    std::string ramal; ///< String que armazena o número do ramal.

    ///
    /// @brief Valida o formato e o intervalo do ramal.
    /// @details Verifica se a string é numérica e se o valor está entre 0 e 50.
    /// @param ramal A string a ser verificada.
    /// @throw std::invalid_argument Se o ramal não for um valor válido entre 00 e 50.
    ///
    void validar(std::string const &ramal);

public:
    ///
    /// @brief Construtor que inicializa o domínio com um valor.
    /// @param ramal String contendo o ramal (ex: "12").
    /// @throw std::invalid_argument Se o ramal inicial for inválido.
    ///
    Ramal(std::string ramal);

    ///
    /// @brief Define um novo número de ramal.
    /// @param ramal A nova string numérica.
    /// @throw std::invalid_argument Se o formato ou intervalo do ramal for inválido.
    ///
    void setRamal(std::string ramal);

    ///
    /// @brief Recupera o número do ramal armazenado.
    /// @return A string contendo o ramal.
    ///
    std::string getRamal();
};

#endif // RAMAL_HPP
