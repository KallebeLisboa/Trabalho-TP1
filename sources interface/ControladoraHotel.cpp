#include "header interface/ControladoraHotel.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// INCLUDES DOS DOMINIOS
#include "header dominios/codigo.hpp"
#include "header dominios/nome.hpp"
#include "header dominios/endereco.hpp"
#include "header dominios/telefone.hpp"

// INCLUDE DA ENTIDADE (Fundamental para o pesquisar funcionar)
#include "header entidades/hotel.hpp"

using namespace std;

// Implementacao do metodo principal
void ControladoraHotel::executar() {
    int opcao;
    do {
        exibirOpcoes();
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore();

        switch (opcao) {
            case 1: criarHotel(); break;
            case 2: lerHotel(); break;
            case 3: editarHotel(); break;
            case 4: excluirHotel(); break;
            case 5: listarHoteis(); break;
            case 0: break;
            default: cout << "\nOpcao invalida." << endl;
        }
    } while (opcao != 0);
}

void ControladoraHotel::exibirOpcoes() {
    cout << "\n--- GERENCIAMENTO DE HOTEIS ---" << endl;
    cout << "1. Criar Novo Hotel" << endl;
    cout << "2. Ler Dados de um Hotel" << endl;
    cout << "3. Editar Hotel" << endl;
    cout << "4. Excluir Hotel" << endl;
    cout << "5. Listar Todos os Hoteis" << endl;
    cout << "0. Voltar ao Menu Principal" << endl;
}

// --- INTEGRAÇÃO REAL: CRIAR HOTEL ---
void ControladoraHotel::criarHotel() {
    string textoCodigo, textoNome, textoEndereco, textoTelefone;

    cout << "\n--- CRIAR HOTEL ---" << endl;

    // 1. Validações dos Domínios
    while (true) {
        cout << "Codigo (10 carac): ";
        getline(cin, textoCodigo);
        try { Codigo c(textoCodigo); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    while (true) {
        cout << "Nome (5-20 carac): ";
        getline(cin, textoNome);
        try { Nome n(textoNome); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    while (true) {
        cout << "Endereco (5-30 carac): ";
        getline(cin, textoEndereco);
        try { Endereco e(textoEndereco); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    while (true) {
        cout << "Telefone (+55 14-digitos): ";
        getline(cin, textoTelefone);
        try { Telefone t(textoTelefone); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 2. CHAMADA AO SERVIÇO
    cout << "Salvando no banco de dados..." << endl;
    try {
        if (servicoHotel == nullptr) {
            cout << "ERRO CRITICO: O servico de hotel nao foi conectado!" << endl;
            return;
        }
        servicoHotel->criarHotel(textoCodigo, textoNome, textoEndereco, textoTelefone);
        cout << "SUCESSO: Hotel criado e salvo no sistema!" << endl;

    } catch (const runtime_error& e) {
        cout << "ERRO AO SALVAR: " << e.what() << endl;
    }
}

// --- INTEGRAÇÃO REAL: LER HOTEL ---
void ControladoraHotel::lerHotel() {
    string textoCodigo;
    cout << "\n--- LER HOTEL ---" << endl;

    while (true) {
        cout << "Informe o Codigo do Hotel (PK): ";
        getline(cin, textoCodigo);
        try { Codigo c(textoCodigo); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    cout << "Buscando no banco de dados..." << endl;

    if (servicoHotel == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    Hotel* hotel = servicoHotel->pesquisarHotel(textoCodigo);

    if (hotel != nullptr) {
        cout << "-----------------------------" << endl;
        cout << "HOTEL ENCONTRADO:" << endl;
        cout << "Codigo:   " << hotel->getCodigo().getCodigo() << endl;
        cout << "Nome:     " << hotel->getNome().getNome() << endl;
        cout << "Endereco: " << hotel->getEndereco().getEndereco() << endl;
        cout << "Telefone: " << hotel->getTelefone().getTelefone() << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Nenhum hotel encontrado com este codigo." << endl;
    }
}

void ControladoraHotel::editarHotel() {
    string textoCodigo, novoNome, novoEndereco, novoTelefone;

    cout << "\n--- EDITAR HOTEL ---" << endl;
    cout << "Informe o Codigo do Hotel que deseja alterar (PK): " << endl;

    // 1. Identificar o Hotel (PK) - Validação Obrigatória
    while (true) {
        cout << "Codigo: ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // Verificação de segurança
    if (servicoHotel == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    cout << "Preencha os novos dados (Pressione ENTER para manter o atual):" << endl;

    // 2. Novo Nome (Opcional)
    cout << "Novo Nome: ";
    getline(cin, novoNome);
    if (!novoNome.empty()) {
        try {
            Nome nome(novoNome); // Testa se é válido
            cout << " - Nome validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: Nome invalido (" << e.what() << "). A alteracao deste campo sera ignorada." << endl;
            novoNome = ""; // Limpa para indicar que não deve alterar
        }
    }

    // 3. Novo Endereço (Opcional)
    cout << "Novo Endereco: ";
    getline(cin, novoEndereco);
    if (!novoEndereco.empty()) {
        try {
            Endereco endereco(novoEndereco); // Testa se é válido
            cout << " - Endereco validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: Endereco invalido (" << e.what() << "). A alteracao deste campo sera ignorada." << endl;
            novoEndereco = "";
        }
    }

    // 4. Novo Telefone (Opcional)
    cout << "Novo Telefone: ";
    getline(cin, novoTelefone);
    if (!novoTelefone.empty()) {
        try {
            Telefone telefone(novoTelefone); // Testa se é válido
            cout << " - Telefone validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: Telefone invalido (" << e.what() << "). A alteracao deste campo sera ignorada." << endl;
            novoTelefone = "";
        }
    }

    // 5. Integração com o Serviço
    try {
        // Envia os dados. O container saberá que string vazia = não alterar.
        servicoHotel->atualizarHotel(textoCodigo, novoNome, novoEndereco, novoTelefone);
        // O container geralmente já imprime uma mensagem de sucesso, mas se quiser pode por aqui também.
    } catch (const runtime_error& e) {
        cout << "FALHA NA EDICAO: " << e.what() << endl;
    }
}
// Excluir Hotel

void ControladoraHotel::excluirHotel() {
    string textoCodigo;
    cout << "\n--- EXCLUIR HOTEL ---" << endl;
    while (true) {
        cout << "Codigo do Hotel a excluir: ";
        getline(cin, textoCodigo);
        try { Codigo c(textoCodigo); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }
    try {
        if (servicoHotel == nullptr) return;
        servicoHotel->excluirHotel(textoCodigo);
        cout << "SUCESSO: Hotel excluido." << endl;
    } catch (const runtime_error& e) {
        cout << "ERRO: " << e.what() << endl;
    }
}

// Listar Hotel

void ControladoraHotel::listarHoteis() {
    cout << "\n--- LISTA DE HOTEIS ---" << endl;

    // 1. Verificação de Segurança
    if (servicoHotel == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    // 2. Busca os dados no Serviço
    map<string, Hotel*> lista = servicoHotel->listarHoteis();

    // 3. Verifica se está vazio
    if (lista.empty()) {
        cout << "Nenhum hotel cadastrado no sistema." << endl;
        return;
    }

    // 4. Itera sobre o mapa e imprime
    cout << "Total de Hoteis: " << lista.size() << endl;
    cout << "---------------------------------" << endl;

    // 'auto const& par' cria uma referência para cada item do mapa (chave, valor)
    for (auto const& par : lista) {
        Hotel* h = par.second; // O 'second' é o ponteiro para o Hotel

        cout << "Codigo:   " << h->getCodigo().getCodigo() << endl;
        cout << "Nome:     " << h->getNome().getNome() << endl;
        cout << "Endereco: " << h->getEndereco().getEndereco() << endl;
        cout << "Telefone: " << h->getTelefone().getTelefone() << endl;
        cout << "---------------------------------" << endl;
    }
}
