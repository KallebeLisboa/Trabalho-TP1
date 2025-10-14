#ifndef IQUARTOSERVICE_HPP_INCLUDED
#define IQUARTOSERVICE_HPP_INCLUDED

#include <stdexcept>
#include <list>
#include "../entidade/Quarto.hpp"
#include "../dominio/Codigo.hpp"
#include "../dominio/Numero.hpp"

///
/// @brief Define os serviços de negócio para o gerenciamento de quartos.
///
/// @details Esta interface especifica o contrato para as operações de CRUD
/// e listagem de quartos, que são sempre vinculados a um hotel.
///
class IQuartoService {
public:
    /// @brief Destrutor virtual padrão.
    virtual ~IQuartoService() {}

    ///
    /// @brief Cadastra um novo quarto no sistema, associado a um hotel.
    /// @param quarto Objeto da entidade Quarto com os dados a serem cadastrados.
    /// @throw std::invalid_argument Lançada se os dados forem inválidos ou se o quarto já existir no hotel.
    ///
    virtual void cadastrarQuarto(const Quarto& quarto) = 0;

    ///
    /// @brief Consulta um quarto específico por número e código do hotel.
    /// @param codigoHotel O código do hotel ao qual o quarto pertence.
    /// @param numeroQuarto O número do quarto a ser consultado.
    /// @return O objeto Quarto correspondente.
    /// @throw std::invalid_argument Lançada se o quarto ou o hotel não forem encontrados.
    ///
    virtual Quarto consultarQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    ///
    /// @brief Edita os dados de um quarto existente.
    /// @param quarto Objeto da entidade Quarto com os dados atualizados.
    /// @throw std::invalid_argument Lançada se os novos dados forem inválidos ou se o quarto não for encontrado.
    ///
    virtual void editarQuarto(const Quarto& quarto) = 0;

    ///
    /// @brief Remove um quarto do sistema.
    /// @param codigoHotel O código do hotel ao qual o quarto pertence.
    /// @param numeroQuarto O número do quarto a ser removido.
    /// @throw std::invalid_argument Lançada se o quarto ou o hotel não forem encontrados.
    ///
    virtual void descadastrarQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    ///
    /// @brief Retorna uma lista com todos os quartos de um determinado hotel.
    /// @param codigoHotel O código do hotel cujos quartos serão listados.
    /// @return Uma lista de objetos Quarto. A lista pode estar vazia.
    ///
    virtual std::list<Quarto> listarQuartos(const Codigo& codigoHotel) = 0;
};

#endif // IQUARTOSERVICE_HPP_INCLUDED
