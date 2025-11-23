#include "header dominios/data.hpp"
#include <stdexcept>   // Para std::invalid_argument
#include <string>      // Para std::stoi e outras funçães de string
#include <algorithm>   // Para std::count e std::find
#include <iterator>    // Para std::begin e std::end

// Implementação do método privado para verificar ano bissexto
bool Data::anoBissexto(int ano){
    if((ano % 4 == 0) && (ano % 100 != 0)){
        return true;
    }
    else if((ano % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
};

// Implementação do método de validação principal
void Data::validar(std::string const &data) {
    // 1. Verifica a estrutura da data (dia-mês-ano).
    int numeroDeHifens = std::count(data.begin(), data.end(), '-');

    if(!(numeroDeHifens == 2)){
        throw std::invalid_argument("Formato de data inválido. Use o formato 'dia-mês-ano'");
    };

    int hifen1 = data.find('-');
    int hifen2 = data.find('-',hifen1+1);

    if(!((hifen1 == 1 && hifen2 == 5) || (hifen1 == 2 && hifen2 == 6))){
        throw std::invalid_argument("Formato de data inválido. Use o formato 'dia-mês-ano");
    }

    std::string dia = data.substr(0,hifen1);
    std::string mes = data.substr(hifen1+1,hifen2 - hifen1 - 1);
    std::string ano = data.substr(hifen2+1);

    // 2. Validar o ano.
    
    int ano_int = std::stoi(ano);
    if(ano_int < 2000 || ano_int > 2999){
        throw std::invalid_argument("Ano deve estar no intervalo 2000 - 2999");
    }
    // 3. Validar o mês.

    std::string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

    bool mesValido = false;

    for(int i = 0; i < 12; i++){
        if(mes == meses[i]){
            mesValido = true;
            break;
        }
    };

    if(!mesValido){
        throw std::invalid_argument("O mês deve ser uma abreviação de três letras em maiúsculas (JAN, FEV, etc.).");
    };

    // 4. Validar o dia.

    int dia_int = std::stoi(dia);

    std::string meses31Dias[] = {"JAN", "MAR", "MAI", "JUL", "AGO", "OUT", "DEZ"};
    std::string meses30Dias[] = {"ABR","JUN", "SET", "NOV"};

    if (std::find(std::begin(meses31Dias), std::end(meses31Dias), mes) != std::end(meses31Dias)) {
        if (dia_int < 1 || dia_int > 31) {
            throw std::invalid_argument("Dia invalido para o mes. Dia deve ser entre 1 e 31.");
        }
    }
    else if(std::find(std::begin(meses30Dias), std::end(meses30Dias), mes) != std::end(meses30Dias)){
        if (dia_int < 1 || dia_int > 30) {
            throw std::invalid_argument("Dia invalido para o mes. Dia deve ser entre 1 e 30.");
        }
    }
    else if(mes == "FEV"){
        if(anoBissexto(ano_int)){
            if (dia_int < 1 || dia_int > 29) {
                throw std::invalid_argument("Dia invalido para o mes. Dia deve ser entre 1 e 29.");
            }
            }
        else{
            if (dia_int < 1 || dia_int > 28) {
                throw std::invalid_argument("Dia invalido para o mes. Dia deve ser entre 1 e 28.");
            }
        }
    }
}

// Implementação dos métodos públicos

Data::Data(std::string data){
    validar(data);
    this->data=data;
};

void Data::setData(std::string data){
    validar(data);
    this->data=data;  
};

std::string Data::getData(){
    return this->data;
};
