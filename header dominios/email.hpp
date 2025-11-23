#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <stdexcept> // Necessário para lançar exceções

    ///
    /// @brief Representa o domínio de endereço de E-mail.
    ///
    /// @details Esta classe armazena e valida endereços de e-mail no formato "parte-local@domínio".
    /// Regras de validação:
    /// 1. Parte local: até 64 caracteres. Permite letras (a-z), dígitos (0-9), ponto (.) e hífen (-).
    ///    Não pode começar ou terminar com ponto ou hífen. Ponto ou hífen deve ser seguido por letra ou dígito.
    /// 2. Domínio: até 255 caracteres. Composto por partes separadas por ponto.
    ///    Permite letras (a-z), dígitos (0-9) e hífen (-). Não pode começar ou terminar com hífen.
    ///
class Email {
private:
    std::string email; ///< String que armazena o endereço de e-mail completo.

    ///
    /// @brief Valida o formato do endereço de e-mail.
    /// @details Verifica o comprimento, a estrutura (presença de @) e as regras de caracteres
    /// para a parte local e o domínio.
    /// @param email A string do e-mail a ser verificada.
    /// @throw std::invalid_argument Se o formato for inválido ou exceder os limites de tamanho.
    ///
    void validar(std::string const &email);

public:
    ///
    /// @brief Construtor que inicializa o e-mail com um valor.
    /// @param email String contendo o endereço de e-mail.
    /// @throw std::invalid_argument Se o e-mail fornecido for inválido.
    ///
    Email(std::string email);

    ///
    /// @brief Define um novo endereço de e-mail.
    /// @param email A nova string de e-mail.
    /// @throw std::invalid_argument Se o formato do e-mail for inválido.
    ///
    void setEmail(std::string email);

    ///
    /// @brief Recupera o endereço de e-mail armazenado.
    /// @return A string contendo o e-mail.
    ///
    std::string getEmail();
};

#endif // EMAIL_HPP
