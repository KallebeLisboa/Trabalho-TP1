#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "Pessoa.hpp" // Inclui a classe base Pessoa
// Ajuste os caminhos abaixo conforme a estrutura exata das suas pastas
#include "../dominio/Endereco.hpp"
#include "../dominio/Cartao.hpp"

///
/// @brief Entidade que representa um Hóspede no sistema.
///
/// @details A classe Hospede é uma especialização da classe Pessoa.
/// Além dos atributos herdados (Nome e Email), ela armazena as informações
/// necessárias para a estadia e faturamento: Endereço e Cartão de Crédito.
///
class Hospede : public Pessoa {
private:
    Endereco endereco; ///< Instância do domínio Endereço.
    Cartao cartao;     ///< Instância do domínio Cartão.

public:
    ///
    /// @brief Construtor que inicializa um Hóspede com todos os seus dados.
    /// @param nome Objeto do domínio Nome (repassado ao construtor de Pessoa).
    /// @param email Objeto do domínio Email (repassado ao construtor de Pessoa).
    /// @param endereco Objeto do domínio Endereço.
    /// @param cartao Objeto do domínio Cartão.
    ///
    Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao);

    ///
    /// @brief Recupera o endereço do hóspede.
    /// @return Objeto do domínio Endereço.
    ///
    Endereco getEndereco() const;

    ///
    /// @brief Recupera os dados do cartão de crédito do hóspede.
    /// @return Objeto do domínio Cartão.
    ///
    Cartao getCartao() const;

    ///
    /// @brief Define um novo endereço para o hóspede.
    /// @param endereco Novo objeto do domínio Endereço.
    ///
    void setEndereco(const Endereco& endereco);

    ///
    /// @brief Define um novo cartão de crédito para o hóspede.
    /// @param cartao Novo objeto do domínio Cartão.
    ///
    void setCartao(const Cartao& cartao);
};

#endif // HOSPEDE_HPP