#ifndef IHOTELSERVICE_HPP_INCLUDED
#define IHOTELSERVICE_HPP_INCLUDED

#include <stdexcept>
#include <list>
#include "../entidade/Hotel.hpp"
#include "../dominio/Codigo.hpp"

///
/// @brief Define os serviços de negócio para o gerenciamento de hotéis.
///
/// @details Esta interface especifica o contrato para as operações de CRUD
/// (Criar, Ler, Atualizar, Deletar) e listagem de hotéis.
///
class IHotelService {
public:
    /// @brief Destrutor virtual padrão.
    virtual ~IHotelService() {}

    ///
    /// @brief Cadastra um novo hotel no sistema.
    /// @param hotel Objeto da entidade Hotel com os dados a serem cadastrados.
    /// @throw std::invalid_argument Lançada se os dados do hotel forem inválidos ou se o código já existir.
    ///
    virtual void cadastrarHotel(const Hotel& hotel) = 0;

    ///
    /// @brief Consulta um hotel pelo seu código de identificação.
    /// @param codigo O código único do hotel a ser consultado.
    /// @return O objeto Hotel correspondente ao código.
    /// @throw std::invalid_argument Lançada se o hotel com o código especificado não for encontrado.
    ///
    virtual Hotel consultarHotel(const Codigo& codigo) = 0;

    ///
    /// @brief Edita os dados de um hotel existente.
    /// @param hotel Objeto da entidade Hotel com os dados atualizados.
    /// @throw std::invalid_argument Lançada se os novos dados forem inválidos ou se o hotel não for encontrado.
    ///
    virtual void editarHotel(const Hotel& hotel) = 0;

    ///
    /// @brief Remove um hotel do sistema.
    /// @param codigo O código único do hotel a ser removido.
    /// @throw std::invalid_argument Lançada se o hotel com o código especificado não for encontrado.
    ///
    virtual void descadastrarHotel(const Codigo& codigo) = 0;

    ///
    /// @brief Retorna uma lista com todos os hotéis cadastrados.
    /// @return Uma lista de objetos Hotel. A lista pode estar vazia se não houver hotéis.
    ///
    virtual std::list<Hotel> listarHoteis() = 0;
};

#endif // IHOTELSERVICE_HPP_INCLUDED
