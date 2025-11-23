#include "../header interface/ControladoraHospede.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// INCLUDES DOS DOMÍNIOS NECESSÁRIOS
#include "../header dominios/nome.hpp"
#include "../header dominios/email.hpp"
#include "../header dominios/endereco.hpp"
#include "../header dominios/cartao.hpp"
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

    // INTEGRAÇÃO
    cout << "Salvando novo hospede..." << endl;
    try {
        // Verificação de segurança
        if (servicoHospede == nullptr) {
            cout << "ERRO CRITICO: Servico de hospede nao conectado." << endl;
            return;
        }

        // Chama o serviço
        servicoHospede->criarHospede(textoNome, textoEmail, textoEndereco, textoCartao);

        cout << "SUCESSO: Hospede cadastrado no sistema!" << endl;

    } catch (const runtime_error& e) {
        cout << "ERRO AO SALVAR: " << e.what() << endl;
    }
}

// Implementacao: Ler Dados de um Hospede
void ControladoraHospede::lerHospede() {
    string textoEmail;
    cout << "\n--- LER HOSPEDE ---" << endl;
    cout << "Informe o Email do Hospede (PK) para buscar." << endl;

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

    cout << "Buscando no sistema..." << endl;

    // 2. Verificação de Segurança
    if (servicoHospede == nullptr) {
        cout << "ERRO CRITICO: Servico de hospede nao conectado." << endl;
        return;
    }

    // 3. Busca no Serviço
    Hospede* h = servicoHospede->pesquisarHospede(textoEmail);

    // 4. Exibe os resultados
    if (h != nullptr) {
        cout << "-----------------------------" << endl;
        cout << "HOSPEDE ENCONTRADO:" << endl;
        cout << "Nome:     " << h->getNome().getNome() << endl;
        cout << "Email:    " << h->getEmail().getEmail() << endl;
        cout << "Endereco: " << h->getEndereco().getEndereco() << endl;
        // Mostra apenas os últimos 4 dígitos do cartão por segurança (opcional, mas boa prática)
        string cartao = h->getCartao().getCartao();
        cout << "Cartao:   XXXX-XXXX-XXXX-" << cartao.substr(12, 4) << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Nenhum hospede encontrado com este email." << endl;
    }
}

// Implementacao: Editar Hospede
void ControladoraHospede::editarHospede() {
    string textoEmail, novoNome, novoEndereco, novoCartao;

    cout << "\n--- EDITAR HOSPEDE ---" << endl;
    cout << "Informe o Email do Hospede para editar (PK):" << endl;

    // 1. Identificar PK
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

    // Segurança
    if (servicoHospede == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    // Verifica existência
    if (servicoHospede->pesquisarHospede(textoEmail) == nullptr) {
        cout << "AVISO: Hospede nao encontrado." << endl;
        return;
    }

    cout << "Preencha os novos dados (Pressione ENTER para manter o atual):" << endl;

    // 2. Novo Nome
    cout << "Novo Nome: ";
    getline(cin, novoNome);
    if (!novoNome.empty()) {
        try {
            Nome nome(novoNome); // Apenas valida
            cout << " - Nome validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
            novoNome = "";
        }
    }

    // 3. Novo Endereço
    cout << "Novo Endereco: ";
    getline(cin, novoEndereco);
    if (!novoEndereco.empty()) {
        try {
            Endereco endereco(novoEndereco); // Apenas valida
            cout << " - Endereco validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
            novoEndereco = "";
        }
    }

    // 4. Novo Cartão
    cout << "Novo Cartao: ";
    getline(cin, novoCartao);
    if (!novoCartao.empty()) {
        try {
            Cartao cartao(novoCartao); // Apenas valida
            cout << " - Cartao validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
            novoCartao = "";
        }
    }

    // INTEGRAÇÃO
    try {
        servicoHospede->atualizarHospede(textoEmail, novoNome, novoEndereco, novoCartao);
    } catch (const runtime_error& e) {
        cout << "FALHA NA EDICAO: " << e.what() << endl;
    }
}

// Implementacao: Excluir Hospede
void ControladoraHospede::excluirHospede() {
    string textoEmail;
    cout << "\n--- EXCLUIR HOSPEDE ---" << endl;
    cout << "ATENCAO: Esta acao nao pode ser desfeita." << endl;

    // 1. Validação do Email (PK)
    while (true) {
        cout << "Digite o Email do Hospede a excluir: ";
        getline(cin, textoEmail);
        try {
            Email email(textoEmail);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Verificação de Segurança
    if (servicoHospede == nullptr) {
        cout << "ERRO CRITICO: Servico de hospede nao conectado." << endl;
        return;
    }

    // 3. Integração com o Serviço
    cout << "Tentando excluir..." << endl;
    try {
        servicoHospede->excluirHospede(textoEmail);
        cout << "SUCESSO: Hospede " << textoEmail << " removido do sistema." << endl;
    } catch (const runtime_error& e) {
        // Captura o erro se o hóspede não existir
        cout << "FALHA NA EXCLUSAO: " << e.what() << endl;
    }
}

// Implementacao: Listar Todos os Hospedes
void ControladoraHospede::listarHospedes() {
    cout << "\n--- LISTA GLOBAL DE HOSPEDES ---" << endl;

    // 1. Verificação de Segurança
    if (servicoHospede == nullptr) {
        cout << "ERRO CRITICO: Servico de hospede nao conectado." << endl;
        return;
    }

    // 2. Busca os dados no Serviço
    map<string, Hospede*> lista = servicoHospede->listarHospedes();

    // 3. Verifica se está vazio
    if (lista.empty()) {
        cout << "Nenhum hospede cadastrado no sistema." << endl;
        return;
    }

    // 4. Itera sobre o mapa e imprime
    cout << "Total de Hospedes: " << lista.size() << endl;
    cout << "---------------------------------" << endl;

    for (auto const& par : lista) {
        Hospede* h = par.second;

        cout << "Nome:     " << h->getNome().getNome() << endl;
        cout << "Email:    " << h->getEmail().getEmail() << endl;
        cout << "Endereco: " << h->getEndereco().getEndereco() << endl;

        // Exibe cartão mascarado por segurança
        string cartao = h->getCartao().getCartao();
        cout << "Cartao:   ****-****-****-" << cartao.substr(12, 4) << endl;
        cout << "---------------------------------" << endl;
    }
}
