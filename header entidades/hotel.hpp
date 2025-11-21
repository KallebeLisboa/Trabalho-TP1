#ifndef HOTEL_HPP
#define HOTEL_HPP

// Ajuste os caminhos abaixo conforme a estrutura exata das suas pastas
#include "../dominio/Nome.hpp"
#include "../dominio/Endereco.hpp"
#include "../dominio/Telefone.hpp"
#include "../dominio/Codigo.hpp"

///
/// @brief Entidade que representa um Hotel no sistema.
///
/// @details A classe Hotel agrupa os domínios que caracterizam um estabelecimento.
/// Ela contém informações de identificação (Código), localização (Endereço) e contato (Telefone).
/// O Código atua como chave primária (PK) e não pode ser alterado após a criação[cite: 18, 21].
///
class Hotel {
private:
    Nome nome;         ///< Instância do domínio Nome.
    Endereco endereco; ///< Instância do domínio Endereço.
    Telefone telefone; ///< Instância do domínio Telefone.
    Codigo codigo;     ///< Instância do domínio Código (Chave Primária).

public:
    ///
    /// @brief Construtor que inicializa um Hotel com todos os seus dados.
    /// @param nome Objeto do domínio Nome.
    /// @param endereco Objeto do domínio Endereço.
    /// @param telefone Objeto do domínio Telefone.
    /// @param codigo Objeto do domínio Código (identificador único).
    ///
    Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo);

    ///
    /// @brief Recupera o nome do hotel.
    /// @return Objeto do domínio Nome.
    ///
    Nome getNome() const;

    ///
    /// @brief Recupera o endereço do hotel.
    /// @return Objeto do domínio Endereço.
    ///
    Endereco getEndereco() const;

    ///
    /// @brief Recupera o telefone de contato do hotel.
    /// @return Objeto do domínio Telefone.
    ///
    Telefone getTelefone() const;

    ///
    /// @brief Recupera o código identificador do hotel.
    /// @return Objeto do domínio Código.
    ///
    Codigo getCodigo() const;

    ///
    /// @brief Define um novo nome para o hotel.
    /// @param nome Novo objeto do domínio Nome.
    ///
    void setNome(const Nome& nome);

    ///
    /// @brief Define um novo endereço para o hotel.
    /// @param endereco Novo objeto do domínio Endereço.
    ///
    void setEndereco(const Endereco& endereco);

    ///
    /// @brief Define um novo telefone para o hotel.
    /// @param telefone Novo objeto do domínio Telefone.
    ///
    void setTelefone(const Telefone& telefone);
};

#endif // HOTEL_HPP