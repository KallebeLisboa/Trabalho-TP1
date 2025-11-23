#include "header interface/ControladoraUsuario.hpp" // Assume-se que o compilador acha este header localmente ou via path
#include <iostream>
#include <string>
#include <stdexcept> // Para capturar as exceções dos domínios

// INCLUDES COM O CAMINHO CORRETO (Baseado na sua imagem)
#include "header dominios/email.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/senha.hpp"

using namespace std;

// Implementacao do metodo principal
void ControladoraUsuario::executar() {
    int opcao;
    do {
        exibirOpcoes();
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore(); // Limpa o buffer do \n após ler o inteiro

        switch (opcao) {
            case 1: lerConta(); break;
            case 2: editarConta(); break;
            case 3: excluirConta(); break;
            case 0: break; // Volta para o Menu Principal
            default: cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}

// Implementacao do menu de opcoes
void ControladoraUsuario::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DA SUA CONTA ---" << endl;
    cout << "1. Ler Dados da Conta" << endl;
    cout << "2. Editar Nome ou Senha" << endl;
    cout << "3. Excluir Conta" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

/// --- INTEGRAÇÃO REAL DO LER CONTA ---
void ControladoraUsuario::lerConta() {
    string textoEmail;

    cout << "\n--- LER CONTA ---" << endl;
    cout << "Confirme o Email da conta (PK): " << endl;

    // 1. Validação do Formato
    while (true) {
        cout << "Email: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    cout << "Buscando no banco de dados..." << endl;

    // 2. CHAMADA AO SERVIÇO (O ContainerGerente)
    // O metodo pesquisarGerente retorna um ponteiro ou nullptr
    Gerente* gerenteEncontrado = servicoUsuario->pesquisarGerente(textoEmail);

    if (gerenteEncontrado != nullptr) {
        cout << "-----------------------------" << endl;
        cout << "DADOS ENCONTRADOS:" << endl;
        // Usamos os métodos get da entidade e depois get do dominio
        cout << "Nome:  " << gerenteEncontrado->getNome().getNome() << endl;
        cout << "Email: " << gerenteEncontrado->getEmail().getEmail() << endl;
        cout << "Ramal: " << gerenteEncontrado->getRamal().getRamal() << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Nenhuma conta encontrada com este email." << endl;
    }
}

// Implementacao: Editar Nome ou Senha
void ControladoraUsuario::editarConta() {
    string textoEmail, novoNome, novaSenha;

    cout << "\n--- EDITAR CONTA ---" << endl;
    cout << "Confirme o Email da conta a ser editada (PK): " << endl;

    // 1. Valida Email (Chave de busca)
    while (true) {
        cout << "Email: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Valida Novo Nome (Opcional)
    cout << "Novo Nome (Deixe vazio para nao alterar): ";
    getline(cin, novoNome);

    if (!novoNome.empty()) {
        try {
            Nome nome(novoNome); // Apenas testa se é válido
            cout << "Nome validado com sucesso." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: O novo nome e invalido (" << e.what() << "). A alteracao sera ignorada." << endl;
            novoNome = ""; // Anula a alteração
        }
    }

    // 3. Valida Nova Senha (Opcional)
    cout << "Nova Senha (Deixe vazio para nao alterar): ";
    getline(cin, novaSenha);

    if (!novaSenha.empty()) {
        try {
            Senha senha(novaSenha); // Apenas testa se é válido
            cout << "Senha validada com sucesso." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: A nova senha e invalida (" << e.what() << "). A alteracao sera ignorada." << endl;
            novaSenha = ""; // Anula a alteração
        }
    }

    // **INTEGRACAO FUTURA:**
    // servicoUsuario->editar(textoEmail, novoNome, novaSenha);

    cout << "Solicitacao de edicao enviada para o sistema." << endl;
}

// Implementacao: Excluir Conta
void ControladoraUsuario::excluirConta() {
    string textoEmail;

    cout << "\n--- EXCLUIR CONTA ---" << endl;
    cout << "ATENCAO: Esta acao nao pode ser desfeita." << endl;
    cout << "Confirme o Email da conta a ser excluida (PK): " << endl;

    // 1. Validação do Email (Domínio)
    while (true) {
        cout << "Email: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Integração com o Serviço
    cout << "Tentando excluir..." << endl;

    try {
        // Chama o método do container através da interface
        servicoUsuario->excluirGerente(textoEmail);

        // Se chegou aqui, é porque não deu erro
        cout << "SUCESSO: A conta " << textoEmail << " foi removida do sistema permanentemente." << endl;

    } catch (const runtime_error& e) {
        // Captura o erro lançado pelo Container (ex: "Gerente nao encontrado")
        cout << "FALHA NA EXCLUSAO: " << e.what() << endl;
    }
}
