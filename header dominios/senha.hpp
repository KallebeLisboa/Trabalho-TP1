#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

///
/// @brief Representa o domínio de Senha de usuário.
///
/// @details Esta classe armazena e valida uma string de senha.
/// Regras complexas de validação definidas no projeto:
/// 1. Tamanho: Exatamente 5 caracteres.
/// 2. Caracteres permitidos: Letras (A-Z, a-z), dígitos (0-9) e caracteres especiais (!, @, #, $, %, &).
/// 3. Requisito de composição: Deve conter pelo menos uma letra maiúscula, uma minúscula, um dígito e um caractere especial.
/// 4. Regra de não-repetição de tipo: Letra não pode ser seguida de letra, e dígito não pode ser seguido de dígito.
///
class Senha {
private:
    std::string senha; ///< String que armazena a senha validada.

    ///
    /// @brief Valida a senha segundo as regras estritas de segurança e formato.
    /// @details Verifica o tamanho (5), a presença de todos os tipos de caracteres exigidos
    /// e a ordem (sem repetição de tipos consecutivos).
    /// @param senha A string a ser verificada.
    /// @throw std::invalid_argument Se a senha violar qualquer uma das regras de formato ou composição.
    ///
    void validar(std::string const &senha);

public:
    ///
    /// @brief Construtor que inicializa a senha com um valor.
    /// @param senha String contendo a senha.
    /// @throw std::invalid_argument Se a senha inicial for inválida.
    ///
    Senha(std::string senha);

    ///
    /// @brief Define uma nova senha.
    /// @param senha A nova string de senha.
    /// @throw std::invalid_argument Se o formato da nova senha for inválido.
    ///
    void setSenha(std::string senha);

    ///
    /// @brief Recupera a senha armazenada.
    /// @return A string contendo a senha.
    ///
    std::string getSenha();
};

#endif // SENHA_HPP
