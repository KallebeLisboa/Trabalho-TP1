#include "header interface/ControladoraReserva.hpp" // Ajuste o caminho se necessario
#include <iostream>
#include <string>
#include <stdexcept> // Para capturar as excecoes

// INCLUDES DOS DOMINIOS NECESSARIOS
#include "header dominios/codigo.hpp"   // PK da Reserva
#include "header dominios/data.hpp"     // Chegada e Partida
#include "header dominios/dinheiro.hpp" // Valor
#include "header dominios/numero.hpp"   // FK do Quarto
#include "header dominios/email.hpp"    // FK do Hospede

using namespace std;

// Implementacao do metodo principal
void ControladoraReserva::executar() {
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
            case 1: criarReserva(); break;
            case 2: lerReserva(); break;
            case 3: editarReserva(); break;
            case 4: excluirReserva(); break;
            case 5: listarReservas(); break;
            case 0: break; // Volta para o Menu Principal
            default: cout << "\nOpcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}

// Implementacao do menu de opcoes
void ControladoraReserva::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DE RESERVAS ---" << endl;
    cout << "1. Criar Nova Reserva" << endl;
    cout << "2. Ler Dados de uma Reserva" << endl;
    cout << "3. Editar Reserva" << endl;
    cout << "4. Excluir Reserva" << endl;
    cout << "5. Listar Todas as Reservas" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

// Implementacao: Criar Nova Reserva
void ControladoraReserva::criarReserva() {
    string textoCodigo, textoChegada, textoPartida, textoValor;
    string textoNumQuarto, textoEmailHospede;

    cout << "\n--- CRIAR RESERVA ---" << endl;

    // 1. Validação do CODIGO DA RESERVA (PK)
    while (true) {
        cout << "Codigo da Reserva (10 carac): ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Validação da DATA DE CHEGADA
    while (true) {
        cout << "Data Chegada (DD-MMM-AAAA, ex: 10-JAN-2025): ";
        getline(cin, textoChegada);
        try {
            Data data(textoChegada);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 3. Validação da DATA DE PARTIDA
    while (true) {
        cout << "Data Partida (DD-MMM-AAAA, ex: 15-JAN-2025): ";
        getline(cin, textoPartida);
        try {
            Data data(textoPartida);
            // Nota: A validação logica se Partida > Chegada deve ser feita pelo Serviço
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 4. Validação do VALOR (Dinheiro)
    while (true) {
        cout << "Valor Total (ex: 500.00): ";
        getline(cin, textoValor);
        try {
            // Tratamento simples para converter string em double
            size_t virgula = textoValor.find(',');
            if (virgula != string::npos) textoValor[virgula] = '.';

            double valorDouble = stod(textoValor);
            Dinheiro dinheiro(valorDouble);
            break;
        } catch (...) {
            cout << "ERRO: Valor monetario invalido. Use apenas numeros." << endl;
        }
    }

    // 5. Identificação do QUARTO (Chave Estrangeira)
    while (true) {
        cout << "Numero do Quarto Reservado (001-999): ";
        getline(cin, textoNumQuarto);
        try {
            Numero numero(textoNumQuarto);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 6. Identificação do HÓSPEDE (Chave Estrangeira)
    while (true) {
        cout << "Email do Hospede Titular: ";
        getline(cin, textoEmailHospede);
        try {
            Email email(textoEmailHospede);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Reserva reserva(codigo, chegada, partida, valor, numQuarto, emailHospede);
    // servicoReserva->criar(reserva);

    cout << "Reserva criada e validada com sucesso! (Simulacao)" << endl;
}

// Implementacao: Ler Dados de uma Reserva
void ControladoraReserva::lerReserva() {
    string textoCodigo;
    cout << "\n--- LER RESERVA ---" << endl;

    while (true) {
        cout << "Digite o Codigo da Reserva (PK): ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // Reserva r = servicoReserva->ler(textoCodigo);

    cout << "Busca por Reserva " << textoCodigo << " realizada." << endl;
}

// Implementacao: Editar Reserva
void ControladoraReserva::editarReserva() {
    string textoCodigo, novaChegada, novaPartida, novoValor;

    cout << "\n--- EDITAR RESERVA ---" << endl;

    // 1. Identificar PK
    while (true) {
        cout << "Digite o Codigo da Reserva a editar (PK): ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    cout << "Preencha os novos dados (Deixe vazio para manter o atual):" << endl;

    // 2. Nova Data Chegada
    cout << "Nova Data Chegada: ";
    getline(cin, novaChegada);
    if (!novaChegada.empty()) {
        try {
            Data data(novaChegada);
            cout << " - Data Chegada validada." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // 3. Nova Data Partida
    cout << "Nova Data Partida: ";
    getline(cin, novaPartida);
    if (!novaPartida.empty()) {
        try {
            Data data(novaPartida);
            cout << " - Data Partida validada." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // 4. Novo Valor
    cout << "Novo Valor: ";
    getline(cin, novoValor);
    if (!novoValor.empty()) {
        try {
            size_t virgula = novoValor.find(',');
            if (virgula != string::npos) novoValor[virgula] = '.';
            double v = stod(novoValor);
            Dinheiro d(v);
            cout << " - Valor validado." << endl;
        } catch (...) {
            cout << "ERRO: Valor invalido. Ignorado." << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoReserva->editar(...);

    cout << "Solicitacao de edicao enviada." << endl;
}

// Implementacao: Excluir Reserva
void ControladoraReserva::excluirReserva() {
    string textoCodigo;
    cout << "\n--- EXCLUIR RESERVA ---" << endl;

    while (true) {
        cout << "Digite o Codigo da Reserva a excluir (PK): ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO FUTURA:**
    // servicoReserva->excluir(textoCodigo);

    cout << "Reserva " << textoCodigo << " enviada para exclusao." << endl;
}

// Implementacao: Listar Todas as Reservas
void ControladoraReserva::listarReservas() {
    cout << "\n--- LISTA DE RESERVAS ---" << endl;

    // **INTEGRAÇÃO FUTURA:**
    // servicoReserva->listarTodos();

    cout << "Listagem solicitada." << endl;
}
