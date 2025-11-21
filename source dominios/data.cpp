#include "header dominios/data.hpp"
#include <stdexcept>   // Para std::invalid_argument
#include <string>      // Para std::stoi e funções de string
#include <algorithm>   // Para std::count e std::find
#include <iterator>    // Para std::begin e std::end
#include <vector>      // Opcional, mas útil se quiser usar vetores em vez de arrays C-style

// Implementação de método auxiliar para verificar ano bissexto

bool Data::anoBissexto(int ano){
    // Regra: Bissexto se divisível por 4 e NÃO por 100, OU se divisível por 400.
    if((ano % 4 == 0) && (ano % 100 != 0)){
        return true;
    }
    else if(ano % 400 == 0){
        return true;
    }
    else{
        return false;
    }
}

// Implementação do método de validação principal

void Data::validar(std::string const &data) {
    // 1. Verifica a estrutura da string (dia-mês-ano).
    // Conta quantos hifens existem na string. Deve haver exatamente 2.
    int numeroDeHifens = std::count(data.begin(), data.end(), '-');

    if(numeroDeHifens != 2){
        throw std::invalid_argument("Formato de data invalido. Use o formato 'DD-MMM-AAAA'.");
    }

    // Encontra as posições dos hifens para separar as partes
    size_t hifen1 = data.find('-');
    size_t hifen2 = data.find('-', hifen1 + 1);

    // Verifica se os hifens estão nas posições esperadas para garantir formato DD-MMM-AAAA
    // Espera-se algo como "01-JAN-2000" (hifen em 2 e 6) ou "1-JAN-2000" (hifen em 1 e 5)
    // O requisito pede "dia-mês-ano", assumiremos formato padrão DD-MMM-AAAA para segurança.
    if(!((hifen1 == 1 && hifen2 == 5) || (hifen1 == 2 && hifen2 == 6))){
         throw std::invalid_argument("Posicao dos separadores invalida.");
    }

    // Extrai as substrings
    std::string dia = data.substr(0, hifen1);
    std::string mes = data.substr(hifen1 + 1, hifen2 - hifen1 - 1);
    std::string ano = data.substr(hifen2 + 1);

    // 2. Validar o Ano.
    // Converte string para inteiro e checa intervalo 2000-2999
    int ano_int;
    try {
        ano_int = std::stoi(ano);
    } catch (...) {
        throw std::invalid_argument("Ano invalido (nao numerico).");
    }

    if(ano_int < 2000 || ano_int > 2999){
        throw std::invalid_argument("Ano deve estar no intervalo 2000 - 2999.");
    }

    // 3. Validar o Mês.
    // Lista de meses válidos conforme requisito
    std::string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    bool mesValido = false;

    // Verifica se o mês extraído existe na lista
    for(int i = 0; i < 12; i++){
        if(mes == meses[i]){
            mesValido = true;
            break;
        }
    }

    if(!mesValido){
        throw std::invalid_argument("Mes invalido. Use abreviacao de tres letras maiusculas (ex: JAN).");
    }

    // 4. Validar o Dia.
    int dia_int;
    try {
        dia_int = std::stoi(dia);
    } catch (...) {
        throw std::invalid_argument("Dia invalido (nao numerico).");
    }

    // Listas de meses com 31 e 30 dias
    std::string meses31Dias[] = {"JAN", "MAR", "MAI", "JUL", "AGO", "OUT", "DEZ"};
    std::string meses30Dias[] = {"ABR", "JUN", "SET", "NOV"};

    // Verifica dia para meses com 31 dias
    if (std::find(std::begin(meses31Dias), std::end(meses31Dias), mes) != std::end(meses31Dias)) {
        if (dia_int < 1 || dia_int > 31) {
            throw std::invalid_argument("Dia invalido para o mes (1-31).");
        }
    }
    // Verifica dia para meses com 30 dias
    else if(std::find(std::begin(meses30Dias), std::end(meses30Dias), mes) != std::end(meses30Dias)){
        if (dia_int < 1 || dia_int > 30) {
            throw std::invalid_argument("Dia invalido para o mes (1-30).");
        }
    }
    // Verifica Fevereiro (bissexto vs não bissexto)
    else if(mes == "FEV"){
        if(anoBissexto(ano_int)){
            if (dia_int < 1 || dia_int > 29) {
                throw std::invalid_argument("Dia invalido para FEV em ano bissexto (1-29).");
            }
        }
        else{
            if (dia_int < 1 || dia_int > 28) {
                throw std::invalid_argument("Dia invalido para FEV (1-28).");
            }
        }
    }
}

// Implementação dos métodos públicos


Data::Data(std::string data){
    validar(data);
    this->data = data;
}

void Data::setData(std::string data){
    validar(data);
    this->data = data;  
}

std::string Data::getData(){
    return this->data;
}