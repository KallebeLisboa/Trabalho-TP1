#ifndef CONTAINER_HOSPEDE_HPP
#define CONTAINER_HOSPEDE_HPP

#include <map>
#include <string>
#include "header entidades/hospede.hpp"
#include "../header interface/IServicoHospede.hpp"

// Outros includes de domínios...
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/cartao.hpp"

using namespace std;

///
/// @brief Classe responsável pelo armazenamento e gestão em memória de objetos Hospede.
///
/// @details Esta classe implementa o padrão Container, atuando como um banco de dados
/// em memória (usando std::map). Ela é responsável por criar, recuperar, atualizar,
/// e remover instâncias da entidade Hospede.
///


// ADICIONE A HERANÇA
class ContainerHospede : public IServicoHospede {
private:

    ///
    /// @brief Estrutura de dados que armazena os ponteiros para os objetos Hospede.
    /// @details A chave do mapa é o Email (string) para acesso rápido, e o valor é o objeto Hospede.
    ///

    map<string, Hospede*> bancoDeHospedes; // Chave: Email

public:

    ///
    /// @brief Destrutor da classe.
    /// @details Responsável por liberar a memória alocada para os objetos Hospede armazenados.
    ///

    ~ContainerHospede();

    ///
    /// @brief Cadastra um novo hóspede no container.
    /// @param nome String representando o nome do hóspede.
    /// @param email String representando o email (chave primária).
    /// @param endereco String representando o endereço.
    /// @param cartao String representando o número do cartão.
    ///

    // Métodos
    void criarHospede(string nome, string email, string endereco, string cartao);

    ///
    /// @brief Pesquisa um hóspede no container pelo email.
    /// @param email O email do hóspede a ser buscado.
    /// @return Ponteiro para o objeto Hospede encontrado, ou nullptr/exceção se não existir.
    ///

    Hospede* pesquisarHospede(string email);

    ///
    /// @brief Retorna a lista completa de hóspedes cadastrados.
    /// @return Um mapa contendo todos os hóspedes (chave: email, valor: objeto Hospede).
    ///

    map<string, Hospede*> listarHospedes();

    ///
    /// @brief Atualiza os dados de um hóspede existente.
    /// @param email O email do hóspede a ser atualizado (usado para busca).
    /// @param novoNome O novo nome a ser definido.
    /// @param novoEndereco O novo endereço a ser definido.
    /// @param novoCartao O novo cartão a ser definido.
    ///

    void atualizarHospede(string email, string novoNome, string novoEndereco, string novoCartao);

    ///
    /// @brief Remove um hóspede do container.
    /// @param email O email do hóspede a ser removido.
    ///

    void excluirHospede(string email);
};

#endif
