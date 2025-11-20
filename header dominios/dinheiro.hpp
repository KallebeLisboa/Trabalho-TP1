#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

#include <stdexcept> // Necessário para lançar exceções

///
/// @brief Representa o domínio de Dinheiro (valor monetário).
///
/// @details Esta classe armazena valores monetários. Para evitar erros de arredondamento
/// típicos de ponto flutuante, o valor é armazenado internamente como um inteiro representando
/// centavos. O intervalo válido é de 0,00 a 1.000.000,00.
///
class Dinheiro {
private:
    int dinheiro; ///< Valor armazenado em centavos (ex: R$ 1,00 é armazenado como 100).

    ///
    /// @brief Valida se o valor em centavos está dentro do intervalo permitido.
    /// @details O valor deve estar entre 0 e 100.000.000 (correspondente a R$ 1.000.000,00).
    /// @param dinheiro O valor em centavos a ser verificado.
    /// @throw std::invalid_argument Se o valor estiver fora do intervalo de 0 a 1.000.000,00.
    ///
    void validar(int const &dinheiro);

public:
    ///
    /// @brief Construtor que inicializa o objeto com um valor monetário.
    /// @details Converte o valor double para centavos antes de armazenar.
    /// @param dinheiro Valor em formato double (ex: 19.99).
    /// @throw std::invalid_argument Se o valor estiver fora do intervalo permitido.
    ///
    Dinheiro(double dinheiro);

    ///
    /// @brief Define um novo valor monetário.
    /// @param dinheiro Novo valor em formato double.
    /// @throw std::invalid_argument Se o valor estiver fora do intervalo permitido.
    ///
    void setDinheiro(double dinheiro);

    ///
    /// @brief Recupera o valor monetário armazenado.
    /// @details Converte o valor interno de centavos de volta para double.
    /// @return O valor em formato double (ex: 19.99).
    ///
    double getDinheiro();
};

#endif // DINHEIRO_HPP