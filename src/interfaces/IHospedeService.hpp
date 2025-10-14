#ifndef IHOSPEDESERVICE_HPP_INCLUDED
#define IHOSPEDESERVICE_HPP_INCLUDED

#include <stdexcept>
#include <list>
#include "../entidade/Hospede.hpp"
#include "../dominio/Email.hpp"

///
/// @brief Define os serviços de negócio para o gerenciamento de hóspedes.
///
/// @details Esta interface especifica o contrato para as operações de CRUD
/// e listagem de hóspedes.
///
class IHospedeService {
public:
    /// @brief Destrutor virtual padrão.
    virtual ~IHospedeService() {}

    ///
    /// @brief Cadastra um novo hóspede no sistema.
    /// @param hospede Objeto da entidade Hospede com os dados a serem cadastrados.
    /// @throw std::invalid_argument Lançada se o email já estiver em uso ou se algum dado for inválido.
    ///
    virtual void cadastrarHospede(const Hospede& hospede) = 0;

    ///
    /// @brief Consulta um hóspede pelo seu email.
    /// @param email O email do hóspede a ser consultado.
    /// @return O objeto Hospede correspondente.
    /// @throw std::invalid_argument Lançada se o hóspede com o email especificado não for encontrado.
    ///
    virtual Hospede consultarHospede(const Email& email) = 0;

    ///
    /// @brief Edita os dados de um hóspede existente.
    /// @param hospede Objeto da entidade Hospede com os dados atualizados.
    /// @throw std::invalid_argument Lançada se os novos dados forem inválidos ou se o hóspede não for encontrado.
    ///
    virtual void editarHospede(const Hospede& hospede) = 0;

    ///
    /// @brief Remove um hóspede do sistema.
    /// @param email O email do hóspede a ser removido.
    /// @throw std::invalid_argument Lançada se o hóspede com o email especificado não for encontrado.
    ///
    virtual void descadastrarHospede(const Email& email) = 0;

    ///
    /// @brief Retorna uma lista com todos os hóspedes cadastrados.
    /// @return Uma lista de objetos Hospede. A lista pode estar vazia.
    ///
    virtual std::list<Hospede> listarHospedes() = 0;
};

#endif // IHOSPEDESERVICE_HPP_INCLUDED
