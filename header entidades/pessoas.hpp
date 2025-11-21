#ifndef PESSOA_HPP
#define PESSOA_HPP

// Ajuste os caminhos abaixo conforme a estrutura exata das suas pastas
#include "../dominio/Nome.hpp"
#include "../dominio/Email.hpp"

///
/// @brief Entidade base que representa uma Pessoa no sistema.
///
/// @details Esta é a classe mãe (base) para as entidades Gerente e Hospede.
/// Ela encapsula os dados comuns a todos os usuários do sistema: Nome e Email.
/// O atributo Email atua como chave primária (PK) para identificar unicamente uma pessoa.
///
class Pessoa {
private:
    Nome nome;   ///< Instância do domínio Nome.
    Email email; ///< Instância do domínio Email (Chave Primária).

public:
    ///
    /// @brief Construtor que inicializa uma Pessoa com nome e email.
    /// @param nome Objeto do domínio Nome.
    /// @param email Objeto do domínio Email.
    ///
    Pessoa(const Nome& nome, const Email& email);

    ///
    /// @brief Recupera o nome da pessoa.
    /// @return Objeto do domínio Nome.
    ///
    Nome getNome() const;

    ///
    /// @brief Recupera o email da pessoa.
    /// @return Objeto do domínio Email.
    ///
    Email getEmail() const;

    ///
    /// @brief Define um novo nome para a pessoa.
    /// @param nome Novo objeto do domínio Nome.
    ///
    void setNome(const Nome& nome);

    // Note que não há setEmail, pois o email é a Chave Primária (PK) e não deve mudar.
};

#endif // PESSOA_HPP