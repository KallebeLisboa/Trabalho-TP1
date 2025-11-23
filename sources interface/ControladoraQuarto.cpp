#include "header interface/ControladoraQuarto.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

// DOMINIOS
#include "header dominios/numero.hpp"
#include "header dominios/capacidade.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/ramal.hpp"
#include "header dominios/codigo.hpp" // <--- Necessário para Código do Hotel

// ENTIDADE
#include "header entidades/quarto.hpp" // <--- Necessário para ler os dados

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
    string textoCodigoHotel, textoNumero, textoCapacidade, textoDiaria, textoRamal;

    cout << "\n--- CRIAR QUARTO ---" << endl;

    // 1. Validação do CÓDIGO DO HOTEL (Necessário para vincular o quarto)
    while (true) {
        cout << "Codigo do Hotel (10 carac): ";
        getline(cin, textoCodigoHotel);
        try {
            Codigo codigo(textoCodigoHotel);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Validação do NUMERO (PK)
    while (true) {
        cout << "Numero do Quarto (001 a 999): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 3. Validação da CAPACIDADE
    while (true) {
        cout << "Capacidade (1, 2, 3 ou 4): ";
        getline(cin, textoCapacidade);
        try {
            int valorCapacidade = stoi(textoCapacidade);
            Capacidade capacidade(valorCapacidade);
            break;
        } catch (...) {
            cout << "ERRO: Digite um numero valido (1-4)." << endl;
        }
    }

    // 4. Validação da DIARIA
    while (true) {
        cout << "Diaria (Ex: 150.00): ";
        getline(cin, textoDiaria);
        try {
            size_t virgula = textoDiaria.find(',');
            if (virgula != string::npos) textoDiaria[virgula] = '.';

            double valorDiaria = stod(textoDiaria);
            Dinheiro diaria(valorDiaria);
            break;
        } catch (...) {
            cout << "ERRO: Valor numerico invalido." << endl;
        }
    }

    // 5. Validação do RAMAL
    while (true) {
        cout << "Ramal (00 a 50): ";
        getline(cin, textoRamal);
        try {
            Ramal ramal(textoRamal);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // **INTEGRAÇÃO REAL**
    cout << "Salvando quarto no sistema..." << endl;
    try {
        if (servicoQuarto == nullptr) {
            cout << "ERRO CRITICO: Servico de quarto nao conectado." << endl;
            return;
        }

        // Conversões necessárias antes de enviar para o serviço
        int capInt = stoi(textoCapacidade);

        size_t virgula = textoDiaria.find(',');
        if (virgula != string::npos) textoDiaria[virgula] = '.';
        double diariaDouble = stod(textoDiaria);

        // Chama o serviço passando o Código do Hotel junto
        servicoQuarto->criarQuarto(textoCodigoHotel, textoNumero, capInt, diariaDouble, textoRamal);

        cout << "SUCESSO: Quarto criado e vinculado ao Hotel " << textoCodigoHotel << "!" << endl;

    } catch (const runtime_error& e) {
        cout << "ERRO AO SALVAR: " << e.what() << endl;
    }
}

// Implementação: Ler Dados de um Quarto
void ControladoraQuarto::lerQuarto() {
    string textoNumero, textoCodigoHotel;

    cout << "\n--- LER QUARTO ---" << endl;
    cout << "Para achar o quarto, informe o Hotel e o Numero." << endl;

    // 1. Pede o Código do Hotel (Parte 1 da Chave)
    while (true) {
        cout << "Codigo do Hotel (10 carac): ";
        getline(cin, textoCodigoHotel);
        try {
            Codigo codigo(textoCodigoHotel);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Pede o Número do Quarto (Parte 2 da Chave)
    while (true) {
        cout << "Numero do Quarto (001 a 999): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    cout << "Buscando no sistema..." << endl;

    // 3. Busca no Serviço
    if (servicoQuarto == nullptr) {
        cout << "ERRO CRITICO: Servico de quarto nao conectado." << endl;
        return;
    }

    Quarto* quarto = servicoQuarto->pesquisarQuarto(textoCodigoHotel, textoNumero);

    // 4. Exibe os resultados
    if (quarto != nullptr) {
        cout << "-----------------------------" << endl;
        cout << "QUARTO ENCONTRADO:" << endl;
        cout << "Hotel:      " << quarto->getCodigoHotel().getCodigo() << endl;
        cout << "Numero:     " << quarto->getNumero().getNumero() << endl;
        // Capacidade retorna int, Ramal retorna int (no domínio) ou string dependendo da sua implementação final
        // Assumindo getters padrão:
        cout << "Capacidade: " << quarto->getCapacidade().getCapacidade() << " pessoas" << endl;
        cout << "Diaria:     R$ " << quarto->getDiaria().getDinheiro() << endl; // getDinheiro retorna double
        cout << "Ramal:      " << quarto->getRamal().getRamal() << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Quarto nao encontrado neste hotel." << endl;
    }
}
// Implementação: Editar Quarto
void ControladoraQuarto::editarQuarto() {
    string textoCodigoHotel, textoNumero, textoCapacidade, textoDiaria, textoRamal;

    // Variáveis para envio (Iniciam com valores que indicam "Não Alterar")
    int envioCapacidade = -1;
    double envioDiaria = -1.0;
    string envioRamal = "";

    cout << "\n--- EDITAR QUARTO ---" << endl;
    cout << "Identifique o Quarto (Digite -1 para manter as informacoes):" << endl;

    // 1. Identificar Hotel (Parte da PK)
    while (true) {
        cout << "Codigo do Hotel: ";
        getline(cin, textoCodigoHotel);
        try { Codigo c(textoCodigoHotel); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 2. Identificar Quarto (Parte da PK)
    while (true) {
        cout << "Numero do Quarto: ";
        getline(cin, textoNumero);
        try { Numero n(textoNumero); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // Verificação de Segurança
    if (servicoQuarto == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    // Tenta achar antes de pedir dados (opcional, mas boa prática de UX)
    if (servicoQuarto->pesquisarQuarto(textoCodigoHotel, textoNumero) == nullptr) {
        cout << "AVISO: Quarto nao encontrado. Operacao cancelada." << endl;
        return;
    }

    cout << "Preencha os novos dados (Pressione ENTER para manter o atual):" << endl;

    // 3. Nova Capacidade
    cout << "Nova Capacidade (1-4): ";
    getline(cin, textoCapacidade);
    if (!textoCapacidade.empty()) {
        try {
            int cap = stoi(textoCapacidade);
            Capacidade c(cap); // Apenas valida
            envioCapacidade = cap; // Se validou, prepara para envio
            cout << " - Capacidade validada." << endl;
        } catch (...) {
            cout << "ERRO: Capacidade invalida. A alteracao sera ignorada." << endl;
        }
    }

    // 4. Nova Diaria
    cout << "Nova Diaria: ";
    getline(cin, textoDiaria);
    if (!textoDiaria.empty()) {
        try {
            size_t virgula = textoDiaria.find(',');
            if (virgula != string::npos) textoDiaria[virgula] = '.';
            double valor = stod(textoDiaria);
            Dinheiro d(valor); // Apenas valida
            envioDiaria = valor; // Se validou, prepara para envio
            cout << " - Diaria validada." << endl;
        } catch (...) {
            cout << "ERRO: Valor invalido. A alteracao sera ignorada." << endl;
        }
    }

    // 5. Novo Ramal
    cout << "Novo Ramal: ";
    getline(cin, textoRamal);
    if (!textoRamal.empty()) {
        try {
            Ramal r(textoRamal); // Apenas valida
            envioRamal = textoRamal; // Se validou, prepara para envio
            cout << " - Ramal validado." << endl;
        } catch (const invalid_argument& e) {
             cout << "ERRO: " << e.what() << ". A alteracao sera ignorada." << endl;
        }
    }

    // **INTEGRAÇÃO REAL**
    try {
        servicoQuarto->atualizarQuarto(textoCodigoHotel, textoNumero, envioCapacidade, envioDiaria, envioRamal);
    } catch (const runtime_error& e) {
        cout << "FALHA NA EDICAO: " << e.what() << endl;
    }
}

// Implementação: Excluir Quarto
void ControladoraQuarto::excluirQuarto() {
    string textoCodigoHotel, textoNumero;

    cout << "\n--- EXCLUIR QUARTO ---" << endl;
    cout << "ATENCAO: Esta acao nao pode ser desfeita." << endl;
    cout << "Informe o Hotel e o Numero do Quarto a ser excluido." << endl;

    // 1. Identificar o Hotel (Parte 1 da Chave)
    while (true) {
        cout << "Codigo do Hotel (10 carac): ";
        getline(cin, textoCodigoHotel);
        try {
            Codigo codigo(textoCodigoHotel);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Identificar o Quarto (Parte 2 da Chave)
    while (true) {
        cout << "Numero do Quarto (001 a 999): ";
        getline(cin, textoNumero);
        try {
            Numero numero(textoNumero);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 3. Verificação de Segurança
    if (servicoQuarto == nullptr) {
        cout << "ERRO CRITICO: Servico de quarto nao conectado." << endl;
        return;
    }

    // 4. Integração com o Serviço
    cout << "Tentando excluir..." << endl;
    try {
        servicoQuarto->excluirQuarto(textoCodigoHotel, textoNumero);
        cout << "SUCESSO: Quarto removido do sistema." << endl;
    } catch (const runtime_error& e) {
        cout << "FALHA NA EXCLUSAO: " << e.what() << endl;
    }
}

// Implementação: Listar Todos os Quartos de um Hotel
void ControladoraQuarto::listarQuartos() {
    string textoCodigoHotel;

    cout << "\n--- LISTA DE QUARTOS ---" << endl;
    cout << "Informe o Hotel para visualizar seus quartos." << endl;

    // 1. Identificar o Hotel (Filtro)
    while (true) {
        cout << "Codigo do Hotel (10 carac): ";
        getline(cin, textoCodigoHotel);
        try {
            Codigo codigo(textoCodigoHotel);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Verificação de Segurança
    if (servicoQuarto == nullptr) {
        cout << "ERRO CRITICO: Servico de quarto nao conectado." << endl;
        return;
    }

    cout << "Buscando quartos..." << endl;

    // 3. Busca no Serviço (Retorna um mapa filtrado apenas com quartos daquele hotel)
    map<string, Quarto*> lista = servicoQuarto->listarQuartosDoHotel(textoCodigoHotel);

    // 4. Verifica se está vazio
    if (lista.empty()) {
        cout << "Nenhum quarto encontrado para o hotel " << textoCodigoHotel << "." << endl;
        return;
    }

    // 5. Exibe a lista
    cout << "---------------------------------" << endl;
    cout << "Total de Quartos: " << lista.size() << endl;
    cout << "---------------------------------" << endl;

    for (auto const& par : lista) {
        Quarto* q = par.second;

        cout << "Numero:     " << q->getNumero().getNumero() << endl;
        cout << "Capacidade: " << q->getCapacidade().getCapacidade() << " pessoas" << endl;
        cout << "Diaria:     R$ " << q->getDiaria().getDinheiro() << endl;
        cout << "Ramal:      " << q->getRamal().getRamal() << endl;
        cout << "---------------------------------" << endl;
    }
}
