#ifndef QUARTO_HPP
#define QUARTO_HPP

#include "../header dominios/numero.hpp"
#include "../header dominios/capacidade.hpp"
#include "../header dominios/dinheiro.hpp"
#include "../header dominios/ramal.hpp"
#include "../header dominios/codigo.hpp"


///
/// @brief Entidade que representa um Quarto no sistema.
///
/// @details A classe Quarto agrupa as informações de uma unidade de hospedagem.
/// Ela contém dados sobre o número do quarto, capacidade de hóspedes, valor da diária
/// e ramal telefônico. Além disso, armazena o código do Hotel (Chave Estrangeira)
/// para vincular este quarto a um estabelecimento específico.
///

class Quarto {
private:
    Numero numero;         ///< Instância do domínio Número (identificação do quarto).
    Capacidade capacidade; ///< Instância do domínio Capacidade (limite de pessoas).
    Dinheiro diaria;       ///< Instância do domínio Dinheiro (valor por noite).
    Ramal ramal;           ///< Instância do domínio Ramal (telefone interno).
    Codigo codigoHotel;    ///< Instância do domínio Código (FK - Referência ao Hotel).

public:

    ///
    /// @brief Construtor que inicializa um Quarto com todos os seus dados.
    /// @param codigoHotel O código do hotel ao qual o quarto pertence.
    /// @param numero O número do quarto.
    /// @param capacidade A capacidade de pessoas do quarto.
    /// @param diaria O valor da diária.
    /// @param ramal O ramal telefônico do quarto.
    ///

    // Construtor completo
    Quarto(const Codigo& codigoHotel, const Numero& numero, const Capacidade& capacidade, const Dinheiro& diaria, const Ramal& ramal);

    // Métodos Get
    ///
    /// @brief Recupera o código do hotel ao qual o quarto pertence.
    /// @return Objeto do domínio Código.
    ///
    Codigo getCodigoHotel() const;

    ///
    /// @brief Recupera o número do quarto.
    /// @return Objeto do domínio Número.
    ///
    Numero getNumero() const;

    ///
    /// @brief Recupera a capacidade do quarto.
    /// @return Objeto do domínio Capacidade.
    ///
    Capacidade getCapacidade() const;

    ///
    /// @brief Recupera o valor da diária.
    /// @return Objeto do domínio Dinheiro.
    ///
    Dinheiro getDiaria() const;

    ///
    /// @brief Recupera o ramal do quarto.
    /// @return Objeto do domínio Ramal.
    ///
    Ramal getRamal() const;

    ///
    /// @brief Define o hotel ao qual este quarto está vinculado.
    /// @param codigoHotel Novo código de hotel.
    ///

    // Métodos Set
    void setCodigoHotel(const Codigo& codigoHotel);

    ///
    /// @brief Define o número do quarto.
    /// @param numero Novo objeto do domínio Número.
    ///
    void setNumero(const Numero& numero);

    ///
    /// @brief Define a capacidade do quarto.
    /// @param capacidade Novo objeto do domínio Capacidade.
    ///
    void setCapacidade(const Capacidade& capacidade);

    ///
    /// @brief Define o valor da diária.
    /// @param diaria Novo objeto do domínio Dinheiro.
    ///
    void setDiaria(const Dinheiro& diaria);

    ///
    /// @brief Define o ramal do quarto.
    /// @param ramal Novo objeto do domínio Ramal.
    ///
    void setRamal(const Ramal& ramal);
};

#endif // QUARTO_HPP
