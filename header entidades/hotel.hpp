#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "../header dominios/nome.hpp"
#include "../header dominios/endereco.hpp"
#include "../header dominios/telefone.hpp"
#include "../header dominios/codigo.hpp"


///
/// @brief Entidade que representa um Hotel no sistema.
///
/// @details A classe Hotel agrupa os domínios que caracterizam um estabelecimento.
/// Ela contém informações de identificação (Código), localização (Endereço) e contato (Telefone).
/// O Código atua como chave primária (PK) e não pode ser alterado após a criação[cite: 18, 21].
///


class Hotel {
private:
    // Atributos são instâncias das classes de Domínio
    Nome nome;///< Instância do domínio Nome.
    Endereco endereco;///< Instância do domínio Endereço.
    Telefone telefone;///< Instância do domínio Telefone.
    Codigo codigo; ///< Instância do domínio Código (Chave Primária).

public:


    ///
    /// @brief Construtor que inicializa um Hotel com todos os seus dados.
    /// @param nome Objeto do domínio Nome.
    /// @param endereco Objeto do domínio Endereço.
    /// @param telefone Objeto do domínio Telefone.
    /// @param codigo Objeto do domínio Código (identificador único).
    ///

    // Construtor
    Hotel(const Nome& nome, const Endereco& endereco, const Telefone& telefone, const Codigo& codigo);

    ///
    /// @brief Recupera o nome do hotel.
    /// @return Objeto do domínio Nome.
    ///


    // Métodos Get (Para acesso aos atributos)
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

    // Métodos Set (Para modificar os atributos)
    // Não é possível editar dado que identifica registro (chave primária).


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
