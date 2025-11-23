#ifndef CONTAINER_GERENTE_HPP
#define CONTAINER_GERENTE_HPP

#include <map>
#include <string>
#include "header entidades/gerente.hpp"
#include "../header interface/IServicoUsuario.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/senha.hpp"
#include "header dominios/ramal.hpp"

using namespace std;

///
/// @brief Classe responsável pelo armazenamento e gestão em memória de objetos Gerente.
///
/// @details Esta classe implementa o padrão Container, atuando como um banco de dados
/// em memória (usando std::map). Ela é responsável por criar, recuperar, atualizar,
/// remover e autenticar instâncias da entidade Gerente.
///

class ContainerGerente : public IServicoUsuario {
private:

    ///
    /// @brief Estrutura de dados que armazena os ponteiros para os objetos Gerente.
    /// @details A chave do mapa é o Email (string) para acesso rápido, e o valor é o objeto Gerente.
    ///

    // Chave: Email (Login)
    map<string, Gerente*> bancoDeGerentes;

public:

    ///
    /// @brief Destrutor da classe.
    /// @details Responsável por liberar a memória alocada para os objetos Gerente armazenados no mapa.
    ///

    ~ContainerGerente();

    ///
    /// @brief Cria um novo gerente e o armazena no container.
    /// @param nome String representando o nome do gerente.
    /// @param email String representando o email (chave primária).
    /// @param ramal String representando o ramal.
    /// @param senha String representando a senha.
    ///


    void criarGerente(string nome, string email, string ramal, string senha);

    ///
    /// @brief Verifica as credenciais de um gerente.
    /// @param email O email fornecido para login.
    /// @param senha A senha fornecida para login.
    /// @return true se as credenciais estiverem corretas, false caso contrário.
    ///


    bool autenticar(string email, string senha);

    ///
    /// @brief Pesquisa um gerente no container pelo email.
    /// @param email O email do gerente a ser buscado.
    /// @return Ponteiro para o objeto Gerente encontrado, ou nullptr/exceção se não existir.
    ///

    Gerente* pesquisarGerente(string email);

    ///
    /// @brief Atualiza os dados de um gerente existente.
    /// @param email O email do gerente a ser atualizado (busca).
    /// @param novoNome O novo nome a ser definido.
    /// @param novoRamal O novo ramal a ser definido.
    /// @param novaSenha A nova senha a ser definida.
    ///

    void atualizarGerente(string email, string novoNome, string novoRamal, string novaSenha);

    ///
    /// @brief Remove um gerente do container.
    /// @param email O email do gerente a ser removido.
    ///

    void excluirGerente(string email);

    ///
    /// @brief Retorna a lista completa de gerentes armazenados.
    /// @return Um mapa contendo todos os gerentes (chave: email, valor: objeto Gerente).
    ///

    map<string, Gerente*> listarGerentes();
};

#endif
