#ifndef NOME_HPP
#define NOME_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

    ///
    /// @brief Representa o domínio de Nome no sistema.
    ///
    /// @details Esta classe armazena e valida uma string de nome.
    /// Regras de validação:
    /// 1. Tamanho: 5 a 20 caracteres.
    /// 2. Caracteres permitidos: Letras (A-Z, a-z) e espaço em branco.
    /// 3. Formatação:
    ///    - O primeiro caractere de cada termo deve ser letra maiúscula (A-Z).
    ///    - Espaços em branco devem ser seguidos por uma letra (não podem ser seguidos por outro espaço ou estar no fim).
    ///    - O último caractere não pode ser espaço.
    ///
class Nome {
private:
    std::string nome; ///< String que armazena o nome validado.

    ///
    /// @brief Valida o formato do nome segundo as regras de negócio.
    /// @details Verifica tamanho, caracteres permitidos, capitalização dos termos e uso de espaços.
    /// @param nome A string a ser verificada.
    /// @throw std::invalid_argument Se o nome violar as regras de tamanho, caracteres ou formatação.
    ///
    void validar(std::string const &nome);

public:
    ///
    /// @brief Construtor que inicializa o nome com um valor.
    /// @param nome String contendo o nome.
    /// @throw std::invalid_argument Se o nome fornecido for inválido.
    ///
    Nome(std::string nome);

    ///
    /// @brief Define um novo nome.
    /// @param nome A nova string de nome.
    /// @throw std::invalid_argument Se o formato do nome for inválido.
    ///
    void setNome(std::string nome);

    ///
    /// @brief Recupera o nome armazenado.
    /// @return A string contendo o nome.
    ///
    std::string getNome();
};

#endif // NOME_HPP
