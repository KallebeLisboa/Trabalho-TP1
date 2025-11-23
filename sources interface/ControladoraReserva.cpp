#include "header interface/ControladoraReserva.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// INCLUDES DOS DOMINIOS NECESSARIOS
#include "header dominios/codigo.hpp"
#include "header dominios/data.hpp"
#include "header dominios/dinheiro.hpp"
#include "header dominios/numero.hpp"
#include "header dominios/email.hpp"

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

// Criar Nova Reserva
void ControladoraReserva::criarReserva() {
    string textoCodigo, textoChegada, textoPartida, textoValor;
    string textoCodigoHotel, textoNumQuarto, textoEmailHospede;

    cout << "\n--- CRIAR RESERVA ---" << endl;

    // 1. CODIGO RESERVA
    while (true) {
        cout << "Codigo da Reserva (10 carac): ";
        getline(cin, textoCodigo);
        try { Codigo c(textoCodigo); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 2. DATA CHEGADA
    while (true) {
        cout << "Data Chegada (DD-MMM-AAAA): ";
        getline(cin, textoChegada);
        try { Data d(textoChegada); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 3. DATA PARTIDA
    while (true) {
        cout << "Data Partida (DD-MMM-AAAA): ";
        getline(cin, textoPartida);
        try { Data d(textoPartida); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 4. VALOR
    while (true) {
        cout << "Valor Total (ex: 500.00): ";
        getline(cin, textoValor);
        try {
            size_t virgula = textoValor.find(',');
            if (virgula != string::npos) textoValor[virgula] = '.';
            double v = stod(textoValor);
            Dinheiro d(v);
            break;
        } catch (...) { cout << "Erro: Valor invalido." << endl; }
    }

    cout << "\n--- VINCULAR HOTEIS E HOSPEDES ---" << endl;

    // 5. CODIGO DO HOTEL (Necessário para achar o quarto)
    while (true) {
        cout << "Codigo do Hotel do Quarto: ";
        getline(cin, textoCodigoHotel);
        try { Codigo c(textoCodigoHotel); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 6. NUMERO DO QUARTO
    while (true) {
        cout << "Numero do Quarto: ";
        getline(cin, textoNumQuarto);
        try { Numero n(textoNumQuarto); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // 7. EMAIL DO HOSPEDE
    while (true) {
        cout << "Email do Hospede Titular: ";
        getline(cin, textoEmailHospede);
        try { Email e(textoEmailHospede); break; } catch (const invalid_argument& e) { cout << "Erro: " << e.what() << endl; }
    }

    // INTEGRAÇÃO
    cout << "Processando reserva..." << endl;
    try {
        if (servicoReserva == nullptr) {
            cout << "ERRO CRITICO: Servico de reserva nao conectado." << endl;
            return;
        }

        // Tratamento do valor double
        size_t virgula = textoValor.find(',');
        if (virgula != string::npos) textoValor[virgula] = '.';
        double valorDouble = stod(textoValor);

        // Chama o serviço
        servicoReserva->criarReserva(textoCodigo, textoChegada, textoPartida, valorDouble, textoEmailHospede, textoCodigoHotel, textoNumQuarto);

        cout << "SUCESSO: Reserva realizada!" << endl;

    } catch (const runtime_error& e) {
        cout << "ERRO AO SALVAR: " << e.what() << endl;
    }
}



// Implementacao: Ler Dados de uma Reserva
void ControladoraReserva::lerReserva() {
    string textoCodigo;
    cout << "\n--- LER RESERVA ---" << endl;
    cout << "Informe o Codigo da Reserva (PK) para visualizar os detalhes." << endl;

    // 1. Validação do Código (PK)
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

    cout << "Buscando no sistema..." << endl;

    // 2. Verificação de Segurança
    if (servicoReserva == nullptr) {
        cout << "ERRO CRITICO: Servico de reserva nao conectado." << endl;
        return;
    }

    // 3. Busca no Serviço (Container)
    Reserva* r = servicoReserva->pesquisarReserva(textoCodigo);

    // 4. Exibe os resultados
    if (r != nullptr) {
        cout << "-----------------------------" << endl;
        cout << "RESERVA ENCONTRADA:" << endl;
        cout << "Codigo:   " << r->getCodigo().getCodigo() << endl;
        cout << "Entrada:  " << r->getChegada().getData() << endl;
        cout << "Saida:    " << r->getPartida().getData() << endl;
        cout << "Valor:    R$ " << r->getValor().getDinheiro() << endl;

        cout << "\n--- DADOS VINCULADOS ---" << endl;
        cout << "Quarto:   " << r->getNumeroQuarto().getNumero() << " (Hotel: " << r->getCodigoHotel().getCodigo() << ")" << endl;
        cout << "Hospede:  " << r->getEmailHospede().getEmail() << endl;
        cout << "-----------------------------" << endl;
    } else {
        cout << "AVISO: Nenhuma reserva encontrada com o codigo " << textoCodigo << "." << endl;
    }
}

// Implementacao: Editar Reserva
void ControladoraReserva::editarReserva() {
    string textoCodigo, novaChegada, novaPartida, novoValor, novoQuarto;

    // Variáveis de envio (iniciam indicando "não alterar")
    double envioValor = -1.0;
    string envioQuarto = "";

    cout << "\n--- EDITAR RESERVA ---" << endl;

    // 1. Identificar a Reserva (PK)
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

    // Segurança
    if (servicoReserva == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    // Verifica se existe antes de pedir dados
    if (servicoReserva->pesquisarReserva(textoCodigo) == nullptr) {
        cout << "AVISO: Reserva nao encontrada. Operacao cancelada." << endl;
        return;
    }

    cout << "Preencha os novos dados (Pressione ENTER para manter o atual):" << endl;

    // 2. Nova Data Chegada
    cout << "Nova Data Chegada (DD-MMM-AAAA): ";
    getline(cin, novaChegada);
    if (!novaChegada.empty()) {
        try {
            Data data(novaChegada); // Valida
            cout << " - Data Chegada validada." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
            novaChegada = ""; // Anula
        }
    }

    // 3. Nova Data Partida
    cout << "Nova Data Partida (DD-MMM-AAAA): ";
    getline(cin, novaPartida);
    if (!novaPartida.empty()) {
        try {
            Data data(novaPartida); // Valida
            cout << " - Data Partida validada." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
            novaPartida = ""; // Anula
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
            Dinheiro d(v); // Valida
            envioValor = v; // Prepara envio
            cout << " - Valor validado." << endl;
        } catch (...) {
            cout << "ERRO: Valor invalido. Ignorado." << endl;
        }
    }

    // 5. Novo Numero do Quarto
    cout << "Novo Numero do Quarto: ";
    getline(cin, novoQuarto);
    if (!novoQuarto.empty()) {
        try {
            Numero n(novoQuarto); // Valida
            envioQuarto = novoQuarto; // Prepara envio
            cout << " - Quarto validado." << endl;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << ". Ignorado." << endl;
        }
    }

    // **INTEGRAÇÃO REAL**
    try {
        servicoReserva->atualizarReserva(textoCodigo, novaChegada, novaPartida, envioValor, envioQuarto);
    } catch (const runtime_error& e) {
        cout << "FALHA NA EDICAO: " << e.what() << endl;
    }
}

// Implementacao: Excluir Reserva
void ControladoraReserva::excluirReserva() {
    string textoCodigo;
    cout << "\n--- EXCLUIR RESERVA ---" << endl;
    cout << "ATENCAO: Esta acao cancela a reserva permanentemente." << endl;

    // 1. Validação do Código (PK)
    while (true) {
        cout << "Digite o Codigo da Reserva a excluir: ";
        getline(cin, textoCodigo);
        try {
            Codigo codigo(textoCodigo);
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Verificação de Segurança
    if (servicoReserva == nullptr) {
        cout << "ERRO CRITICO: Servico de reserva nao conectado." << endl;
        return;
    }

    // 3. Integração com o Serviço
    cout << "Processando cancelamento..." << endl;
    try {
        servicoReserva->excluirReserva(textoCodigo);
        cout << "SUCESSO: Reserva " << textoCodigo << " cancelada e removida do sistema." << endl;
    } catch (const runtime_error& e) {
        // Captura o erro caso a reserva não exista
        cout << "FALHA NA EXCLUSAO: " << e.what() << endl;
    }
}

// Implementacao: Listar Reservas de um Hotel
void ControladoraReserva::listarReservas() {
    string textoCodigoHotel;

    cout << "\n--- LISTA DE RESERVAS POR HOTEL ---" << endl;
    cout << "Informe o Hotel para visualizar as reservas agendadas." << endl;

    // 1. Identificar o Hotel (Filtro)
    while (true) {
        cout << "Codigo do Hotel (10 carac): ";
        getline(cin, textoCodigoHotel);
        try {
            Codigo c(textoCodigoHotel); // Valida formato
            break;
        } catch (const invalid_argument& e) {
            cout << "ERRO: " << e.what() << endl;
        }
    }

    // 2. Segurança
    if (servicoReserva == nullptr) {
        cout << "ERRO CRITICO: Servico nao conectado." << endl;
        return;
    }

    cout << "Buscando reservas..." << endl;

    // 3. Busca Filtrada
    map<string, Reserva*> lista = servicoReserva->listarReservasDoHotel(textoCodigoHotel);

    // 4. Exibe
    if (lista.empty()) {
        cout << "Nenhuma reserva encontrada para o hotel " << textoCodigoHotel << "." << endl;
        return;
    }

    cout << "---------------------------------" << endl;
    cout << "Total de Reservas: " << lista.size() << endl;
    cout << "---------------------------------" << endl;

    for (auto const& par : lista) {
        Reserva* r = par.second;

        cout << "Cod Reserva: " << r->getCodigo().getCodigo() << endl;
        cout << "Periodo:     " << r->getChegada().getData() << " ate " << r->getPartida().getData() << endl;
        cout << "Quarto:      " << r->getNumeroQuarto().getNumero() << endl;
        cout << "Hospede:     " << r->getEmailHospede().getEmail() << endl;
        cout << "Valor:       R$ " << r->getValor().getDinheiro() << endl;
        cout << "---------------------------------" << endl;
    }
}
