#include "header interface/ControladoraQuarto.hpp" // Ajuste o caminho conforme sua estrutura
#include <iostream>
#include <string>
#include <stdexcept> // Para capturar as excecoes
#include <limits>    // Para numeric_limits

// INCLUDES DOS DOMINIOS
#include "header dominios/numero.hpp"
#include "header dominios/capacidade.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/ramal.hpp"

using namespace std;

// Implementação do método principal
void ControladoraQuarto::executar() {
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
            case 1: criarQuarto(); break;
            case 2: lerQuarto(); break;
            case 3: editarQuarto(); break;
            case 4: excluirQuarto(); break;
            case 5: listarQuartos(); break;
            case 0: break; // Volta para o Menu Principal
            default: cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}

// Implementação do menu de opções
void ControladoraQuarto::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DE QUARTOS ---" << endl;
    cout << "1. Criar Novo Quarto" << endl;
    cout << "2. Ler Dados de um Quarto" << endl;
    cout << "3. Editar Quarto" << endl;
    cout << "4. Excluir Quarto" << endl;
    cout << "5. Listar Todos os Quartos" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

// Implementação: Criar Novo Quarto
void ControladoraQuarto::criarQuarto() {
    string textoNumero, textoCapacidade, textoDiaria, textoRamal;

    cout << "\n--- CRIAR QUARTO ---" << endl;

    // 1. Validação do NUMERO (PK)
    while (true) {
        cout << "Numero (001 a 999): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero); // Valida formato string
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Validação da CAPACIDADE (Int)
    while (true) {
        cout << "Capacidade (1, 2, 3 ou 4): ";
        getline(cin, textoCapacidade);
        try {
            // Converte string para int antes de passar para o Dominio
            int valorCapacidade = stoi(textoCapacidade);
            Capacidade capacidade(valorCapacidade); // Valida regra do dominio
            break;
        } catch (const invalid_argument& e) {
            // Captura erro do stoi (se não for numero) ou do dominio
            cout << "ERRO: Digite um numero valido (1-4)." << endl;
        } catch (...) {
            cout << "ERRO: Entrada invalida." << endl;
        }
    }

    // 3. Validação da DIARIA (Dinheiro - Double)
    while (true) {
        cout << "Diaria (Ex: 150.00): ";
        getline(cin, textoDiaria);
        try {
            // Converte string para double (troca virgula por ponto se necessario, mas stod padrao usa ponto)
            size_t virgula = textoDiaria.find(',');
            if (virgula != string::npos) textoDiaria[virgula] = '.';

            double valorDiaria = stod(textoDiaria);
            Dinheiro diaria(valorDiaria); // Valida regra do dominio
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        } catch (...) {
            cout << "ERRO: Valor numerico invalido." << endl;
        }
    }

    // 4. Validação do RAMAL (String)
    while (true) {
        cout << "Ramal (00 a 50): ";
        getline(cin, textoRamal);
        try {
            Ramal ramal(textoRamal); // Valida formato string
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Quarto quarto(numero, capacidade, diaria, ramal);
    // servicoQuarto->criar(quarto);

    cout << "Quarto criado e validado com sucesso! (Simulacao)" << endl;
}

// Implementação: Ler Dados de um Quarto
void ControladoraQuarto::lerQuarto() {
    string textoNumero;
    cout << "\n--- LER QUARTO ---" << endl;

    while (true) {
        cout << "Digite o Numero do Quarto (PK - 001 a 999): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Quarto q = servicoQuarto->ler(textoNumero);

    cout << "Busca por Quarto " << textoNumero << " realizada." << endl;
}

// Implementação: Editar Quarto
void ControladoraQuarto::editarQuarto() {
    string textoNumero, textoCapacidade, textoDiaria, textoRamal;

    cout << "\n--- EDITAR QUARTO ---" << endl;

    // 1. Identificar PK
    while (true) {
        cout << "Digite o Numero do Quarto a editar (PK): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    cout << "Preencha os novos dados (Deixe vazio para manter o atual):" << endl;

    // 2. Nova Capacidade
    cout << "Nova Capacidade: ";
    getline(cin, textoCapacidade);
    if (!textoCapacidade.empty()) {
        try {
            int valorCap = stoi(textoCapacidade);
            Capacidade capacidade(valorCap);
            cout << " - Capacidade validada." << endl;
        } catch (...) {
            cout << "ERRO: Capacidade invalida. Alteracao ignorada." << endl;
        }
    }

    // 3. Nova Diaria
    cout << "Nova Diaria: ";
    getline(cin, textoDiaria);
    if (!textoDiaria.empty()) {
        try {
            size_t virgula = textoDiaria.find(',');
            if (virgula != string::npos) textoDiaria[virgula] = '.';
            double valorDin = stod(textoDiaria);
            Dinheiro diaria(valorDin);
            cout << " - Diaria validada." << endl;
        } catch (...) {
            cout << "ERRO: Valor invalido. Alteracao ignorada." << endl;
        }
    }

    // 4. Novo Ramal
    cout << "Novo Ramal: ";
    getline(cin, textoRamal);
    if (!textoRamal.empty()) {
        try {
            Ramal ramal(textoRamal);
            cout << " - Ramal validado." << endl;
        } catch (const invalid_argument& e) {
             cout << "ERRO: " << e.what() << ". Alteracao ignorada." << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoQuarto->editar(...);

    cout << "Solicitacao de edicao enviada." << endl;
}

// Implementação: Excluir Quarto
void ControladoraQuarto::excluirQuarto() {
    string textoNumero;
    cout << "\n--- EXCLUIR QUARTO ---" << endl;

    while (true) {
        cout << "Digite o Numero do Quarto a excluir (PK): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoQuarto->excluir(textoNumero);

    cout << "Quarto " << textoNumero << " enviado para exclusao." << endl;
}

// Implementação: Listar Todos os Quartos
void ControladoraQuarto::listarQuartos() {
    cout << "\n--- LISTA DE QUARTOS ---" << endl;

    // **INTEGRAÇÃO FUTURA:**
    // servicoQuarto->listarTodos();

    cout << "Listagem solicitada." << endl;
}
