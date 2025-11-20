#ifndef TELEFONE_HPP
#define TELEFONE_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

///
/// @brief Representa o domínio de Telefone.
///
/// @details Esta classe armazena e valida uma string representando um número de telefone.
/// Regras de validação:
/// 1. Formato: "+DDDDDDDDDDDDDD" (sinal de mais seguido por 14 dígitos).
/// 2. Total de 15 caracteres.
/// 3. Cada caractere após o '+' deve ser um dígito (0-9).
///
class Telefone {
private:
    std::string telefone; ///< String que armazena o número de telefone formatado.

    ///
    /// @brief Valida o formato do telefone.
    /// @details Verifica se o tamanho é 15, se começa com '+' e se os demais caracteres são dígitos.
    /// @param telefone A string a ser verificada.
    /// @throw std::invalid_argument Se o formato não seguir o padrão "+DDDDDDDDDDDDDD".
    ///
    void validar(std::string const &telefone);

public:
    ///
    /// @brief Construtor que inicializa o telefone com um valor.
    /// @param telefone String contendo o número de telefone.
    /// @throw std::invalid_argument Se o telefone inicial for inválido.
    ///
    Telefone(std::string telefone);

    ///
    /// @brief Define um novo número de telefone.
    /// @param telefone A nova string de telefone.
    /// @throw std::invalid_argument Se o formato do novo telefone for inválido.
    ///
    void setTelefone(std::string telefone);

    ///
    /// @brief Recupera o número de telefone armazenado.
    /// @return A string contendo o telefone.
    ///
    std::string getTelefone();
};

#endif // TELEFONE_HPP