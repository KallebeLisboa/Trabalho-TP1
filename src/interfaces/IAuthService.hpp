#ifndef IAUTHSERVICE_HPP_INCLUDED
#define IAUTHSERVICE_HPP_INCLUDED

#include <stdexcept>
#include "../entidade/Gerente.hpp"
#include "../dominio/Email.hpp"
#include "../dominio/Senha.hpp"

///
/// @brief Define os serviços de autenticação e gerenciamento de contas de gerente.
///
/// @details Esta interface especifica o contrato para cadastrar, autenticar e
/// gerenciar as contas de usuários gerentes do sistema.
///
class IAuthService {
public:
    /// @brief Destrutor virtual padrão.
    virtual ~IAuthService() {}

    ///
    /// @brief Cadastra uma nova conta de gerente no sistema.
    /// @param gerente Objeto da entidade Gerente com os dados a serem cadastrados.
    /// @throw std::invalid_argument Lançada se o email informado já estiver em uso ou se algum dado for inválido.
    ///
    virtual void cadastrarGerente(const Gerente& gerente) = 0;

    ///
    /// @brief Autentica um gerente para acesso ao sistema.
    /// @param email O email do gerente que está tentando o acesso.
    /// @param senha A senha do gerente.
    /// @return O objeto Gerente correspondente se as credenciais forem válidas.
    /// @throw std::invalid_argument Lançada se as credenciais forem inválidas.
    ///
    virtual Gerente autenticar(const Email& email, const Senha& senha) = 0;

    ///
    /// @brief Edita os dados de uma conta de gerente existente.
    /// @param gerente Objeto da entidade Gerente com os dados atualizados.
    /// @throw std::invalid_argument Lançada se o gerente não for encontrado ou se os novos dados forem inválidos.
    ///
    virtual void editarConta(const Gerente& gerente) = 0;

    ///
    /// @brief Remove uma conta de gerente do sistema.
    /// @param email O email da conta que será removida.
    /// @throw std::invalid_argument Lançada se o gerente com o email especificado não for encontrado.
    ///
    virtual void descadastrarGerente(const Email& email) = 0;
};

#endif // IAUTHSERVICE_HPP_INCLUDED
