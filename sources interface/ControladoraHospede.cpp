#include "header interface/ControladoraHospede.hpp" // Ajuste o caminho se necessário
#include <iostream>
#include <string>
#include <stdexcept> // Para capturar as exceções

// INCLUDES DOS DOMÍNIOS NECESSÁRIOS
#include "header dominios/nome.hpp"
#include "header dominios/email.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/cartao.hpp"

using namespace std;

// Implementacao do metodo principal
void ControladoraHospede::executar() {
    int opcao;
    do {
        exibirOpcoes();
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore(); // Limpa o buffer do \n

        switch (opcao) {
            case 1: criarHospede(); break;
            case 2: lerHospede(); break;
            case 3: editarHospede(); break;
            case 4: excluirHospede(); break;
            case 5: listarHospedes(); break;
            case 0: break; // Volta para o Menu Principal
            default: cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}

// Implementacao do menu de opcoes
void ControladoraHospede::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DE HOSPEDES ---" << endl;
    cout << "1. Criar Novo Hospede" << endl;
    cout << "2. Ler Dados de um Hospede" << endl;
    cout << "3. Editar Hospede" << endl;
    cout << "4. Excluir Hospede" << endl;
    cout << "5. Listar Todos os Hospedes" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

// Implementacao: Criar Novo Hospede
void ControladoraHospede::criarHospede() {
    string textoNome, textoEmail, textoEndereco, textoCartao;

    cout << "\n--- CRIAR HOSPEDE ---" << endl;

    // 1. Validação do NOME
    while (true) {
        cout << "Nome (5-20 carac, Maiusculas): ";
        getline(cin, textoNome);
        try {
            Nome nome(textoNome);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Validação do EMAIL (PK)
    while (true) {
        cout << "Email (ex: nome@dominio.com): ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 3. Validação do ENDEREÇO
    while (true) {
        cout << "Endereco (5-30 carac): ";
        getline(cin, textoEndereco);
        try {
            Endereco endereco(textoEndereco);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 4. Validação do CARTÃO (Luhn)
    while (true) {
        cout << "Cartao (16 digitos): ";
        getline(cin, textoCartao);
        try {
            Cartao cartao(textoCartao);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Hospede hospede(nome, email, endereco, cartao);
    // servicoHospede->criar(hospede);

    cout << "Hospede criado e validado com sucesso! (Simulacao)" << endl;
}

// Implementacao: Ler Dados de um Hospede
void ControladoraHospede::lerHospede() {
    string textoEmail;
    cout << "\n--- LER HOSPEDE ---" << endl;

    while (true) {
        cout << "Digite o Email do Hospede (PK): ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Hospede h = servicoHospede->ler(textoEmail);

    cout << "Busca por Hospede " << textoEmail << " realizada." << endl;
}

// Implementacao: Editar Hospede
void ControladoraHospede::editarHospede() {
    string textoEmail, novoNome, novoEndereco, novoCartao;

    cout << "\n--- EDITAR HOSPEDE ---" << endl;

    // 1. Identificar PK
    while (true) {
        cout << "Digite o Email do Hospede a editar (PK): ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    cout << "Preencha os novos dados (Deixe vazio para manter o atual):" << endl;

    // 2. Novo Nome
    cout << "Novo Nome: ";
    getline(cin, novoNome);
    if (!novoNome.empty()) {
        try {
            Nome nome(novoNome);
            cout << " - Nome validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // 3. Novo Endereço
    cout << "Novo Endereco: ";
    getline(cin, novoEndereco);
    if (!novoEndereco.empty()) {
        try {
            Endereco endereco(novoEndereco);
            cout << " - Endereco validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // 4. Novo Cartão
    cout << "Novo Cartao: ";
    getline(cin, novoCartao);
    if (!novoCartao.empty()) {
        try {
            Cartao cartao(novoCartao);
            cout << " - Cartao validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoHospede->editar(...);

    cout << "Solicitacao de edicao enviada." << endl;
}

// Implementacao: Excluir Hospede
void ControladoraHospede::excluirHospede() {
    string textoEmail;
    cout << "\n--- EXCLUIR HOSPEDE ---" << endl;

    while (true) {
        cout << "Digite o Email do Hospede a excluir (PK): ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoHospede->excluir(textoEmail);

    cout << "Hospede " << textoEmail << " enviado para exclusao." << endl;
}

// Implementacao: Listar Todos os Hospedes
void ControladoraHospede::listarHospedes() {
    cout << "\n--- LISTA DE HOSPEDES ---" << endl;

    // **INTEGRAÇÃO FUTURA:**
    // servicoHospede->listarTodos();

    cout << "Listagem solicitada." << endl;
}
