#include "header dominios/data.hpp"
#include <stdexcept>   // Para std::invalid_argument
#include <string>      // Para std::stoi e outras funçães de string
#include <algorithm>   // Para std::count e std::find
#include <iterator>    // Para std::begin e std::end

// Implementação do método privado para verificar ano bissexto
bool Data::anoBissexto(int ano) const {
    if ((ano % 4 == 0) && (ano % 100 != 0)) {
        return true;
    } else if ((ano % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// Implementação do método de validação principal
void Data::validar(const std::string& data) {
    // 1. Verifica a estrutura da data (dia-mês-ano).
    int numeroDeHifens = std::count(data.begin(), data.end(), '-');
    if (numeroDeHifens != 2) {
        throw std::invalid_argument("Formato de data invalido. Use o formato 'dia-mes-ano'.");
    }

    size_t hifen1 = data.find('-');
    size_t hifen2 = data.find('-', hifen1 + 1);

    if (hifen1 == std::string::npos || hifen2 == std::string::npos) {
         throw std::invalid_argument("Formato de data invalido. Hifens ausentes.");
    }

    std::string dia_str = data.substr(0, hifen1);
    std::string mes_str = data.substr(hifen1 + 1, hifen2 - hifen1 - 1);
    std::string ano_str = data.substr(hifen2 + 1);

    // 2. Validar o ano.
    int ano = std::stoi(ano_str);
    if (ano < 2000 || ano > 2999) {
        throw std::invalid_argument("Ano deve estar no intervalo 2000 - 2999.");
    }

    // 3. Validar o mês.
    const std::string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    bool mesValido = false;
    for (int i = 0; i < 12; i++) {
        if (mes_str == meses[i]) {
            mesValido = true;
            break;
        }
    }
    if (!mesValido) {
        throw std::invalid_argument("O mes deve ser uma abreviacao de tres letras em maiusculas (JAN, FEV, etc.).");
    }

    // 4. Validar o dia.
    int dia = std::stoi(dia_str);
    const std::string meses31Dias[] = {"JAN", "MAR", "MAI", "JUL", "AGO", "OUT", "DEZ"};
    const std::string meses30Dias[] = {"ABR", "JUN", "SET", "NOV"};

    if (std::find(std::begin(meses31Dias), std::end(meses31Dias), mes_str) != std::end(meses31Dias)) {
        if (dia < 1 || dia > 31) {
            throw std::invalid_argument("Dia invalido para o mes. Deve ser entre 1 e 31.");
        }
    } else if (std::find(std::begin(meses30Dias), std::end(meses30Dias), mes_str) != std::end(meses30Dias)) {
        if (dia < 1 || dia > 30) {
            throw std::invalid_argument("Dia invalido para o mes. Deve ser entre 1 e 30.");
        }
    } else if (mes_str == "FEV") {
        if (anoBissexto(ano)) {
            if (dia < 1 || dia > 29) {
                throw std::invalid_argument("Dia invalido para o mes em ano bissexto. Deve ser entre 1 e 29.");
            }
        } else {
            if (dia < 1 || dia > 28) {
                throw std::invalid_argument("Dia invalido para o mes. Deve ser entre 1 e 28.");
            }
        }
    }
}

// Implementação dos métodos públicos

Data::Data(const std::string& dataCompleta) {
    validar(dataCompleta);
    this->data = dataCompleta;
}

void Data::setData(const std::string& dataCompleta) {
    validar(dataCompleta);
    this->data = dataCompleta;
}

std::string Data::getData() const {
    return this->data;
}
