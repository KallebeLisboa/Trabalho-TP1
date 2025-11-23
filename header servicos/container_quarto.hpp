#ifndef CONTAINER_QUARTO_HPP
#define CONTAINER_QUARTO_HPP

#include <map>
#include <string>
#include "header entidades/quarto.hpp"
#include "../header interface/IServicoQuarto.hpp"

// Includes dos domínios necessários para instanciar no .cpp
#include "header dominios/numero.hpp"
#include "header dominios/capacidade.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/ramal.hpp"
#include "header dominios/codigo.hpp"

using namespace std;

///
/// @brief Classe responsável pelo armazenamento e gestão em memória de objetos Quarto.
///
/// @details Esta classe implementa o padrão Container para a entidade Quarto.
/// Diferente de outras entidades, o Quarto não possui uma chave única global (vários hotéis
/// podem ter o quarto "101"). Por isso, este container implementa uma lógica de
/// chave composta (Código do Hotel + Número do Quarto) para garantir a unicidade no mapa.
///


class ContainerQuarto : public IServicoQuarto {
private:

    ///
    /// @brief Armazena os ponteiros para os objetos Quarto.
    /// @details A chave é uma string composta gerada pelo método gerarChave (ex: "HOTEL1_101").
    ///

    // Chave: "CODIGOHOTEL_NUMERO"
    map<string, Quarto*> bancoDeQuartos;

    ///
    /// @brief Método auxiliar para gerar a chave composta única do mapa.
    /// @param codigoHotel O código do hotel.
    /// @param numeroQuarto O número do quarto.
    /// @return Uma string combinada (ex: "CODIGO_NUMERO").
    ///

    // Helper para gerar chave composta
    string gerarChave(string codigoHotel, string numeroQuarto) {
        return codigoHotel + "_" + numeroQuarto;
    }

public:

    ///
    /// @brief Destrutor da classe.
    /// @details Libera a memória dos objetos Quarto armazenados.
    ///

    ~ContainerQuarto();

    ///
    /// @brief Cria um novo quarto e o armazena no container.
    /// @details Recebe tipos primitivos para facilitar a integração com a camada de apresentação,
    /// instanciando os Domínios internamente.
    /// @param codigoHotel Código do hotel ao qual o quarto pertence.
    /// @param numero Número do quarto.
    /// @param capacidade Capacidade de pessoas (int).
    /// @param valorDiaria Valor da diária (double).
    /// @param ramal Ramal telefônico.
    ///

    void criarQuarto(string codigoHotel, string numero, int capacidade, double valorDiaria, string ramal);

    ///
    /// @brief Lista apenas os quartos pertencentes a um hotel específico.
    /// @param codigoHotel O código do hotel para filtrar a busca.
    /// @return Um mapa contendo os quartos encontrados.
    ///


    // --- NOVO MÉTODO DECLARADO ---
    Quarto* pesquisarQuarto(string codigoHotel, string numero);

    map<string, Quarto*> listarQuartosDoHotel(string codigoHotel);

    ///
    /// @brief Atualiza os dados de um quarto existente.
    /// @param codigoHotel Código do hotel (parte da chave primária composta).
    /// @param numero Número do quarto (parte da chave primária composta).
    /// @param novaCapacidade Nova capacidade a ser definida.
    /// @param novoValor Novo valor da diária.
    /// @param novoRamal Novo ramal.
    ///

    void atualizarQuarto(string codigoHotel, string numero, int novaCapacidade, double novoValor, string novoRamal);

    ///
    /// @brief Remove um quarto do container.
    /// @param codigoHotel Código do hotel.
    /// @param numero Número do quarto.
    ///

    void excluirQuarto(string codigoHotel, string numero);
};

#endif
