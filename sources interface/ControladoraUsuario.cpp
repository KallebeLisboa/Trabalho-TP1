#include "header interface/ControladoraUsuario.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// INCLUDES COM O CAMINHO CORRETO
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

// Menu de opcoes
void ControladoraUsuario::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DA SUA CONTA ---" << endl;
    cout << "1. Ler Dados da Conta" << endl;
    cout << "2. Editar Nome ou Senha" << endl;
    cout << "3. Excluir Conta" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

// LER CONTA
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
        cout << "Nome:  " << gerenteEncontrado->getNome().getNome() << endl;
        cout << "Email: " << gerenteEncontrado->getEmail().getEmail() << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Nenhuma conta encontrada com este email." << endl;
    }
}

//Editar Conta
void ControladoraUsuario::editarConta() {
    string textoEmail, novoNome, novaSenha;
    // Criamos uma string vazia para o Ramal, já que não vamos pedir isso agora
    string novoRamal = "";

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

    // Verificação de segurança antes de continuar
    if (servicoUsuario == nullptr) {
        cout << "ERRO CRITICO: Servico de usuario nao conectado." << endl;
        return;
    }

    // Verifica se a conta existe antes de pedir os dados novos
    if (servicoUsuario->pesquisarGerente(textoEmail) == nullptr) {
        cout << "AVISO: Nenhuma conta encontrada com este email." << endl;
        return;
    }

    cout << "Preencha os novos dados (Pressione ENTER para manter o atual):" << endl;

    // 2. Valida Novo Nome (Opcional)
    cout << "Novo Nome: ";
    getline(cin, novoNome);

    if (!novoNome.empty()) {
        try {
            Nome nome(novoNome); // Apenas testa se é válido
            cout << " - Nome validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: O novo nome e invalido (" << e.what() << "). A alteracao sera ignorada." << endl;
            novoNome = ""; // Anula a alteração
        }
    }

    // 3. Valida Nova Senha (Opcional)
    cout << "Nova Senha: ";
    getline(cin, novaSenha);

    if (!novaSenha.empty()) {
        try {
            Senha senha(novaSenha); // Apenas testa se é válido
            cout << " - Senha validada." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: A nova senha e invalida (" << e.what() << "). A alteracao sera ignorada." << endl;
            novaSenha = ""; // Anula a alteração
        }
    }

    // INTEGRAÇÃO
    try {
        // Passamos novoRamal como "" para indicar que não queremos alterá-lo
        servicoUsuario->atualizarGerente(textoEmail, novoNome, novoRamal, novaSenha);

        // O container já imprime mensagem de sucesso, mas se quiser reforçar:
        // cout << "Sucesso!" << endl;
    } catch (const runtime_error& e) {
        cout << "FALHA NA EDICAO: " << e.what() << endl;
    }
}
// Excluir Conta
void ControladoraUsuario::excluirConta() {
    string textoEmail;

    cout << "\n--- EXCLUIR CONTA ---" << endl;
    cout << "ATENCAO: Esta acao nao pode ser desfeita." << endl;
    cout << "Confirme o Email da conta a ser excluida (PK): " << endl;

    // 1. Validação do Email
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

        cout << "SUCESSO: A conta " << textoEmail << " foi removida do sistema permanentemente." << endl;

    } catch (const runtime_error& e) {
        // Captura o erro lançado pelo Container
        cout << "FALHA NA EXCLUSAO: " << e.what() << endl;
    }
}
