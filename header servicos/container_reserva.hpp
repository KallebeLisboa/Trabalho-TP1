#ifndef CONTAINER_RESERVA_HPP
#define CONTAINER_RESERVA_HPP

#include <map>
#include <string>
#include "header entidades/reserva.hpp"
#include "../header interface/IServicoReserva.hpp"

// Includes Domínios
#include "header dominios/data.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/codigo.hpp"
#include "header dominios/email.hpp"
#include "header dominios/numero.hpp"

using namespace std;

///
/// @brief Classe responsável pelo armazenamento e gestão em memória de objetos Reserva.
///
/// @details Esta classe implementa o padrão Container para a entidade Reserva.
/// Atua como um banco de dados em memória, permitindo criar, listar, atualizar e excluir
/// reservas, mantendo a integridade dos dados e as referências para Hóspedes e Quartos.
///


// HERANÇA
class ContainerReserva : public IServicoReserva {
private:

    ///
    /// @brief Estrutura de dados que armazena os ponteiros para os objetos Reserva.
    /// @details A chave do mapa é o Código da Reserva (string) para acesso rápido e único.
    ///

    map<string, Reserva*> bancoDeReservas;

public:

    ///
    /// @brief Destrutor da classe.
    /// @details Libera a memória alocada para os objetos Reserva armazenados.
    ///

    ~ContainerReserva();

    ///
    /// @brief Cria uma nova reserva e a armazena no container.
    /// @param codigo Código único da reserva (PK).
    /// @param dataEntrada Data de check-in.
    /// @param dataSaida Data de check-out.
    /// @param valor Valor total da reserva.
    /// @param emailHospede Email do hóspede titular (FK).
    /// @param codigoHotel Código do hotel (FK).
    /// @param numeroQuarto Número do quarto reservado (FK).
    ///

    void criarReserva(string codigo, string dataEntrada, string dataSaida, double valor, string emailHospede, string codigoHotel, string numeroQuarto);

    // Declaração do pesquisar aqui para os próximos passos
    Reserva* pesquisarReserva(string codigo);

    ///
    /// @brief Retorna a lista completa de reservas cadastradas.
    /// @return Um mapa contendo todas as reservas (chave: código, valor: objeto Reserva).
    ///

    map<string, Reserva*> listarReservasDoHotel(string codigoHotel);

    ///
    /// @brief Atualiza os dados mutáveis de uma reserva.
    /// @param codigo O código da reserva a ser atualizada (usado para busca).
    /// @param novaDataEntrada Nova data de check-in.
    /// @param novaDataSaida Nova data de check-out.
    /// @param novoValor Novo valor total.
    ///

    void atualizarReserva(string codigo, string novaDataEntrada, string novaDataSaida, double novoValor, string novoNumeroQuarto);

    ///
    /// @brief Remove uma reserva do container.
    /// @param codigo O código da reserva a ser removida.
    ///

    void excluirReserva(string codigo);
};

#endif
