#ifndef RESERVA_HPP
#define RESERVA_HPP

// Ajuste os caminhos abaixo conforme a estrutura exata das suas pastas
#include "../dominio/Data.hpp"
#include "../dominio/Dinheiro.hpp"
#include "../dominio/Codigo.hpp"
#include "../dominio/Numero.hpp" // Para identificar o Quarto
#include "../dominio/Email.hpp"  // Para identificar o Hóspede

///
/// @brief Entidade que representa uma Reserva no sistema.
///
/// @details A classe Reserva é responsável por vincular um Hóspede a um Quarto em um determinado período.
/// Ela armazena as datas de chegada e partida, o valor total e o código único da reserva (PK).
/// Além disso, mantém as Chaves Estrangeiras (FK) para relacionar a reserva ao Hóspede (Email),
/// ao Quarto (Número) e ao Hotel (Código do Hotel) correspondentes.
///
class Reserva {
private:
    Data chegada;   ///< Instância do domínio Data (Data de Check-in).
    Data partida;   ///< Instância do domínio Data (Data de Check-out).
    Dinheiro valor; ///< Instância do domínio Dinheiro (Custo total da reserva).
    Codigo codigo;  ///< Instância do domínio Código (Chave Primária da Reserva).

    Numero numeroQuarto; ///< Chave Estrangeira: Número do quarto reservado.
    Email emailHospede;  ///< Chave Estrangeira: Email do hóspede titular.
    Codigo codigoHotel;  ///< Chave Estrangeira: Código do hotel onde o quarto se localiza.

public:
    ///
    /// @brief Construtor que inicializa uma Reserva com todos os seus dados e relacionamentos.
    /// @param chegada Data de início da estadia.
    /// @param partida Data de término da estadia.
    /// @param valor Valor monetário total da reserva.
    /// @param codigo Código único identificador da reserva.
    /// @param emailHospede Email do hóspede responsável.
    /// @param numeroQuarto Número do quarto reservado.
    /// @param codigoHotel Código do hotel onde está o quarto.
    ///
    Reserva(const Data& chegada, const Data& partida, const Dinheiro& valor, const Codigo& codigo, const Email& emailHospede, const Numero& numeroQuarto, const Codigo& codigoHotel);

    ///
    /// @brief Recupera a data de chegada (check-in).
    /// @return Objeto do domínio Data.
    ///
    Data getChegada() const;

    ///
    /// @brief Recupera a data de partida (check-out).
    /// @return Objeto do domínio Data.
    ///
    Data getPartida() const;

    ///
    /// @brief Recupera o valor total da reserva.
    /// @return Objeto do domínio Dinheiro.
    ///
    Dinheiro getValor() const;

    ///
    /// @brief Recupera o código identificador da reserva.
    /// @return Objeto do domínio Código.
    ///
    Codigo getCodigo() const;

    ///
    /// @brief Recupera o email do hóspede titular da reserva.
    /// @return Objeto do domínio Email.
    ///
    Email getEmailHospede() const;

    ///
    /// @brief Recupera o número do quarto reservado.
    /// @return Objeto do domínio Número.
    ///
    Numero getNumeroQuarto() const;

    ///
    /// @brief Recupera o código do hotel da reserva.
    /// @return Objeto do domínio Código.
    ///
    Codigo getCodigoHotel() const;

    ///
    /// @brief Define uma nova data de chegada.
    /// @param chegada Novo objeto do domínio Data.
    ///
    void setChegada(const Data& chegada);

    ///
    /// @brief Define uma nova data de partida.
    /// @param partida Novo objeto do domínio Data.
    ///
    void setPartida(const Data& partida);

    ///
    /// @brief Define um novo valor total para a reserva.
    /// @param valor Novo objeto do domínio Dinheiro.
    ///
    void setValor(const Dinheiro& valor);

    ///
    /// @brief Define o hóspede titular da reserva.
    /// @param emailHospede Novo objeto do domínio Email.
    ///
    void setEmailHospede(const Email& emailHospede);

    ///
    /// @brief Define o número do quarto reservado.
    /// @param numeroQuarto Novo objeto do domínio Número.
    ///
    void setNumeroQuarto(const Numero& numeroQuarto);

    ///
    /// @brief Define o hotel da reserva.
    /// @param codigoHotel Novo objeto do domínio Código.
    ///
    void setCodigoHotel(const Codigo& codigoHotel);
};

#endif // RESERVA_HPP