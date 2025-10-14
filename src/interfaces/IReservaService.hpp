#ifndef IRESERVASERVICE_HPP_INCLUDED
#define IRESERVASERVICE_HPP_INCLUDED

#include <stdexcept>
#include <list>
#include "../entidade/Reserva.hpp"
#include "../dominio/Codigo.hpp"

///
/// @brief Define os serviços de negócio para o gerenciamento de reservas.
///
/// @details Esta interface especifica o contrato para as operações de CRUD
/// e listagem de reservas de quartos.
///
class IReservaService {
public:
    /// @brief Destrutor virtual padrão.
    virtual ~IReservaService() {}

    ///
    /// @brief Cadastra uma nova reserva no sistema.
    /// @param reserva Objeto da entidade Reserva com os dados a serem cadastrados.
    /// @throw std::invalid_argument Lançada se os dados forem inválidos, se houver conflito de datas ou se o código já existir.
    ///
    virtual void cadastrarReserva(const Reserva& reserva) = 0;

    ///
    /// @brief Consulta uma reserva pelo seu código de identificação.
    /// @param codigo O código único da reserva a ser consultada.
    /// @return O objeto Reserva correspondente.
    /// @throw std::invalid_argument Lançada se a reserva com o código especificado não for encontrada.
    ///
    virtual Reserva consultarReserva(const Codigo& codigo) = 0;

    ///
    /// @brief Edita os dados de uma reserva existente.
    /// @param reserva Objeto da entidade Reserva com os dados atualizados.
    /// @throw std::invalid_argument Lançada se os novos dados forem inválidos ou se a reserva não for encontrada.
    ///
    virtual void editarReserva(const Reserva& reserva) = 0;

    ///
    /// @brief Remove uma reserva do sistema.
    /// @param codigo O código único da reserva a ser removida.
    /// @throw std::invalid_argument Lançada se a reserva com o código especificado não for encontrada.
    ///
    virtual void descadastrarReserva(const Codigo& codigo) = 0;

    ///
    /// @brief Retorna uma lista com todas as reservas cadastradas.
    /// @return Uma lista de objetos Reserva. A lista pode estar vazia.
    ///
    virtual std::list<Reserva> listarReservas() = 0;
};
#endif // IRESERVASERVICE_HPP_INCLUDED
