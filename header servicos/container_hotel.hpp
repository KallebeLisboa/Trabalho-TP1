#ifndef CONTAINER_HOTEL_HPP
#define CONTAINER_HOTEL_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>

// Inclusão das Entidades
#include "header entidades/hotel.hpp"
#include "header dominios/codigo.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/telefone.hpp"

// Interface
#include "../header interface/IServicoHotel.hpp"

using namespace std;

///
/// @brief Classe responsável pelo armazenamento e gestão em memória de objetos Hotel.
///
/// @details Esta classe implementa o padrão Container, atuando como um banco de dados
/// em memória (usando std::map). Ela é responsável por gerenciar o ciclo de vida
/// (CRUD) das instâncias da entidade Hotel.
///


class ContainerHotel : public IServicoHotel {
private:

    ///
    /// @brief Estrutura de dados que armazena os ponteiros para os objetos Hotel.
    /// @details A chave do mapa é o Código do hotel (string) para acesso rápido.
    ///

    // Armazena os hotéis
    map<string, Hotel*> bancoDeHoteis;

public:

    ///
    /// @brief Destrutor da classe.
    /// @details Responsável por liberar a memória alocada para os objetos Hotel armazenados.
    ///

    // Destrutor
    ~ContainerHotel();

    ///
    /// @brief Cria um novo hotel e o armazena no container.
    /// @param codigo String representando o código do hotel (chave primária).
    /// @param nome String representando o nome do hotel.
    /// @param endereco String representando o endereço.
    /// @param telefone String representando o telefone.
    ///


    // Métodos CRUD
    void criarHotel(string codigo, string nome, string endereco, string telefone);

    ///
    /// @brief Pesquisa um hotel no container pelo código.
    /// @param codigo O código do hotel a ser buscado.
    /// @return Ponteiro para o objeto Hotel encontrado, ou nullptr se não existir.
    ///

    Hotel* pesquisarHotel(string codigo);

    ///
    /// @brief Retorna a lista completa de hotéis cadastrados.
    /// @return Um mapa contendo todos os hotéis (chave: código, valor: objeto Hotel).
    ///

    map<string, Hotel*> listarHoteis();

    ///
    /// @brief Atualiza os dados de um hotel existente.
    /// @details O código (PK) não pode ser alterado, apenas os outros atributos.
    /// @param codigo O código do hotel a ser atualizado (usado para busca).
    /// @param novoNome O novo nome a ser definido.
    /// @param novoEndereco O novo endereço a ser definido.
    /// @param novoTelefone O novo telefone a ser definido.
    ///


    void atualizarHotel(string codigo, string novoNome, string novoEndereco, string novoTelefone);

    ///
    /// @brief Remove um hotel do container.
    /// @param codigo O código do hotel a ser removido.
    ///

    void excluirHotel(string codigo);
};

#endif
