#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "Pessoa.hpp" // Inclui a classe base Pessoa
// Ajuste os caminhos abaixo conforme a estrutura exata das suas pastas
#include "../dominio/Ramal.hpp"
#include "../dominio/Senha.hpp"

///
/// @brief Entidade que representa um Gerente no sistema.
///
/// @details A classe Gerente é uma especialização da classe Pessoa[cite: 29, 33].
/// Além dos atributos herdados (Nome e Email), ela armazena e gerencia
/// os dados específicos de acesso e contato interno: Ramal e Senha.
///
class Gerente : public Pessoa {
private:
    Ramal ramal; ///< Instância do domínio Ramal.
    Senha senha; ///< Instância do domínio Senha.

public:
    ///
    /// @brief Construtor que inicializa um Gerente com todos os seus dados.
    /// @param nome Objeto do domínio Nome (repassado ao construtor de Pessoa).
    /// @param email Objeto do domínio Email (repassado ao construtor de Pessoa).
    /// @param ramal Objeto do domínio Ramal.
    /// @param senha Objeto do domínio Senha.
    ///
    Gerente(const Nome& nome, const Email& email, const Ramal& ramal, const Senha& senha);

    ///
    /// @brief Recupera o ramal do gerente.
    /// @return Objeto do domínio Ramal.
    ///
    Ramal getRamal() const;

    ///
    /// @brief Recupera a senha do gerente.
    /// @return Objeto do domínio Senha.
    ///
    Senha getSenha() const;

    ///
    /// @brief Define um novo ramal para o gerente.
    /// @param ramal Novo objeto do domínio Ramal.
    ///
    void setRamal(const Ramal& ramal);

    ///
    /// @brief Define uma nova senha para o gerente.
    /// @param senha Novo objeto do domínio Senha.
    ///
    void setSenha(const Senha& senha);
};

#endif // GERENTE_HPP