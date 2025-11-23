#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "Pessoa.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/cartao.hpp"


///
/// @brief Entidade que representa um Hóspede no sistema.
///
/// @details A classe Hospede é uma especialização da classe Pessoa.
/// Além dos atributos herdados (Nome e Email), ela armazena as informações
/// necessárias para a estadia e faturamento: Endereço e Cartão de Crédito.
///

class Hospede : public Pessoa {
private:
    // Atributos são instâncias das classes de Domínio específicas
    Endereco endereco; ///< Instância do domínio Endereço.
    Cartao cartao; ///< Instância do domínio Cartão.

public:


    ///
    /// @brief Construtor que inicializa um Hóspede com todos os seus dados.
    /// @param nome Objeto do domínio Nome (repassado ao construtor de Pessoa).
    /// @param email Objeto do domínio Email (repassado ao construtor de Pessoa).
    /// @param endereco Objeto do domínio Endereço.
    /// @param cartao Objeto do domínio Cartão.
    ///

    // Construtor
    Hospede(const Nome& nome, const Email& email, const Endereco& endereco, const Cartao& cartao);

    ///
    /// @brief Recupera o endereço do hóspede.
    /// @return Objeto do domínio Endereço.
    ///

    // Métodos Get para atributos específicos
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


    // Métodos Set para atributos específicos
    void setEndereco(const Endereco& endereco);

    ///
    /// @brief Define um novo cartão de crédito para o hóspede.
    /// @param cartao Novo objeto do domínio Cartão.
    ///

    void setCartao(const Cartao& cartao);

};

#endif // HOSPEDE_HPP
