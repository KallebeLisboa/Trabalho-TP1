#include "header interface/ControladoraApresentacao.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// Inclusão dos cabeçalhos dos DOMÍNIOS
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/senha.hpp"


using namespace std;

// --- Implementação de criarConta ---
bool ControladoraApresentacao::criarConta() {
    string textoNome, textoEmail, textoSenha;

    cout << "\n--- CRIAR CONTA DE GERENTE ---" << endl;

    // 1. Validação do NOME
    while (true) {
        cout << "Digite seu Nome (Iniciais maiusculas): ";
        getline(cin, textoNome);
        try {
            Nome nome(textoNome);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO no Nome: " << e.what() << "\nTente novamente." << endl;
        }
    }

    // 2. Validação do EMAIL
    while (true) {
        cout << "Digite seu Email: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO no Email: " << e.what() << "\nTente novamente." << endl;
        }
    }

    // 3. Validação da SENHA
    while (true) {
        cout << "Digite sua Senha (5 carac: Aa#1): ";
        getline(cin, textoSenha);
        try {
            Senha senha(textoSenha);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO na Senha: " << e.what() << "\nTente novamente." << endl;
        }
    }

    // --- INTEGRAÇÃO REAL COM O SERVIÇO ---
    try {
        // O Ramal é obrigatório na entidade Gerente, vamos colocar "00" como padrão na criação inicial
        // ou você poderia pedir para o usuário digitar. Vou usar "00" para simplificar.
        servicoUsuario->criarGerente(textoNome, textoEmail, "00", textoSenha);

        cout << "\nConta criada com sucesso no Banco de Dados!" << endl;
        return true;

    } catch (const runtime_error& e) {
        cout << "ERRO AO SALVAR: " << e.what() << endl;
        return false;
    }
}

// --- Implementação de autenticar ---
bool ControladoraApresentacao::autenticar() {
    string textoEmail, textoSenha;

    cout << "\n--- AUTENTICACAO ---" << endl;

    while (true) {
        cout << "Email: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "Formato de Email invalido: " << e.what() << endl;
        }
    }

    cout << "Senha: ";
    getline(cin, textoSenha);

    // --- INTEGRAÇÃO REAL COM O SERVIÇO ---
    if (servicoUsuario->autenticar(textoEmail, textoSenha)) {
        cout << "\nLogin realizado com sucesso!" << endl;
        return true;
    } else {
        cout << "\nFalha no Login: Email nao encontrado ou senha incorreta." << endl;
        return false;
    }
}

// --- Implementação do Menu Principal ---
void ControladoraApresentacao::mostrarMenuPrincipal() {
    int opcao;

    do {
        cout << "\n--- MENU PRINCIPAL DE SERVICOS ---" << endl;
        cout << "1. Gerenciar CONTA do Gerente" << endl;
        cout << "2. Gerenciar HOTEIS" << endl;
        cout << "3. Gerenciar QUARTOS" << endl;
        cout << "4. Gerenciar RESERVAS" << endl;
        cout << "5. Gerenciar HOSPEDES" << endl;
        cout << "0. Sair do Sistema" << endl;
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore();

        switch (opcao) {
            case 1:
                controladoraUsuario.executar();
                break;
            case 2:
                controladoraHotel.executar();
                break;
            case 3:
                controladoraQuarto.executar();
                break;
            case 4:
                controladoraReserva.executar();
                break;
            case 5:
                controladoraHospede.executar();
                break;
            case 0:
                cout << "\nSaindo... Ate logo!" << endl;
                break;
            default:
                cout << "\nOpcao invalida." << endl;
        }
    } while (opcao != 0);
}

// --- Método Executar (Entrada do Programa) ---
void ControladoraApresentacao::executar() {
    // Verificação de segurança
    if (servicoUsuario == nullptr) {
        cout << "ERRO CRITICO: O sistema de servicos nao foi configurado no main." << endl;
        return;
    }

    int opcao;
    bool logado = false;

    while (!logado) {
        cout << "\n--- BEM-VINDO AO GESTOR DE HOTEIS ---" << endl;
        cout << "1. Autenticar (Ja tenho conta)" << endl;
        cout << "2. Criar Conta de Gerente" << endl;
        cout << "0. Sair do Sistema" << endl;
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore();

        switch (opcao) {
            case 1:
                logado = autenticar();
                break;
            case 2:
                criarConta();
                break;
            case 0:
                return;
            default:
                cout << "\nOpcao invalida." << endl;
        }
    }

    if (logado) {
        mostrarMenuPrincipal();
    }
}
