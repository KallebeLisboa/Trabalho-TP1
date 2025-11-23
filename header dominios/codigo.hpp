#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>

    ///
    /// @brief Representa o domínio de Código identificador no sistema.
    ///
    /// @details Esta classe armazena e valida uma string que representa um código único.
    /// Regras de formato:
    /// 1. Deve conter exatamente 10 caracteres.
    /// 2. Cada caractere deve ser uma letra (a-z) ou um dígito (0-9).
    ///
class Codigo {
private:
    std::string codigo; ///< String que armazena o valor do código.

    ///
    /// @brief Valida o formato da string do código.
    /// @details Verifica se o tamanho é 10 e se todos os caracteres são alfanuméricos.
    /// @param codigo A string a ser verificada.
    /// @throw std::invalid_argument Se o tamanho for diferente de 10 ou contiver caracteres inválidos.
    ///
    void validar(const std::string& codigo);

public:
    ///
    /// @brief Construtor que inicializa o código com um valor.
    /// @param codigo String contendo o código inicial.
    /// @throw std::invalid_argument Se o formato do código for inválido.
    ///
    Codigo(std::string codigo);

    ///
    /// @brief Define um novo valor para o código.
    /// @param codigo A nova string de código.
    /// @throw std::invalid_argument Se o formato do código fornecido for inválido.
    ///
    void setCodigo(std::string codigo);

    ///
    /// @brief Recupera o valor do código armazenado.
    /// @return A string contendo o código.
    ///
    std::string getCodigo() const;
};

#endif // CODIGO_HPP
