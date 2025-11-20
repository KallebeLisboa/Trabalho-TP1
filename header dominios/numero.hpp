#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

///
/// @brief Representa o domínio de Número (geralmente associado a um quarto).
///
/// @details Esta classe armazena e valida uma string numérica que representa um número.
/// Regras de validação:
/// 1. O valor deve representar um número inteiro.
/// 2. O intervalo válido é de 001 a 999.
///
class Numero {
private:
    std::string numero; ///< String que armazena o número.

    ///
    /// @brief Valida o formato e o intervalo do número.
    /// @details Verifica se a string é numérica e se o valor está entre 1 e 999.
    /// @param numero A string a ser verificada.
    /// @throw std::invalid_argument Se o número não for um valor válido entre 001 e 999.
    ///
    void validar(std::string const &numero);

public:
    ///
    /// @brief Construtor que inicializa o domínio com um valor.
    /// @param numero String contendo o número (ex: "104").
    /// @throw std::invalid_argument Se o número inicial for inválido.
    ///
    Numero(std::string numero);

    ///
    /// @brief Define um novo número.
    /// @param numero A nova string numérica.
    /// @throw std::invalid_argument Se o formato ou intervalo do número for inválido.
    ///
    void setNumero(std::string numero);

    ///
    /// @brief Recupera o número armazenado.
    /// @return A string contendo o número.
    ///
    std::string getNumero();
};

#endif // NUMERO_HPP