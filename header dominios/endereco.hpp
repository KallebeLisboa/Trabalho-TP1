#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

    ///
    /// @brief Representa o domínio de Endereço no sistema.
    ///
    /// @details Esta classe armazena e valida uma string de endereço.
    /// Regras de validação:
    /// 1. Tamanho: 5 a 30 caracteres.
    /// 2. Caracteres permitidos: Letras (A-Z, a-z), dígitos (0-9), vírgula, ponto e espaço.
    /// 3. Regras de pontuação: Vírgula e ponto não podem ser seguidos por outra pontuação.
    /// 4. Regras de espaço: Espaço deve ser seguido por letra ou dígito.
    /// 5. Posição: Não pode começar ou terminar com ponto, vírgula ou espaço.
    ///
class Endereco {
private:
    std::string endereco; ///< String que armazena o endereço validado.

    ///
    /// @brief Valida o formato do endereço segundo as regras de negócio.
    /// @param endereco A string a ser verificada.
    /// @throw std::invalid_argument Se o endereço violar as regras de tamanho, caracteres ou formatação.
    ///
    void validar(std::string const &endereco);

public:
    ///
    /// @brief Construtor que inicializa o endereço com um valor.
    /// @param endereco String contendo o endereço.
    /// @throw std::invalid_argument Se o endereço fornecido for inválido.
    ///
    Endereco(std::string endereco);

    ///
    /// @brief Define um novo endereço.
    /// @param endereco A nova string de endereço.
    /// @throw std::invalid_argument Se o formato do endereço for inválido.
    ///
    void setEndereco(std::string endereco);

    ///
    /// @brief Recupera o endereço armazenado.
    /// @return A string contendo o endereço.
    ///
    std::string getEndereco();
};

#endif // ENDERECO_HPP
