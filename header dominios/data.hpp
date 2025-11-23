#ifndef DATA_HPP
#define DATA_HPP

#include <string>

    ///
    /// @brief Representa o domínio de Data no sistema.
    ///
    /// @details Esta classe armazena e valida uma data no formato "DD-MMM-AAAA".
    /// Regras de validação:
    /// 1. Dia: 1 a 31 (considerando o mês e ano bissexto).
    /// 2. Mês: JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.
    /// 3. Ano: 2000 a 2999.
    /// 4. Deve considerar anos bissextos para validação de dias.
    ///
class Data {
private:
    std::string data; ///< String que armazena a data formatada (ex: "25-DEZ-2025").

    ///
    /// @brief Verifica se um determinado ano é bissexto.
    /// @param ano O ano a ser verificado (inteiro).
    /// @return true se for bissexto, false caso contrário.
    ///
    bool anoBissexto(int ano);

    ///
    /// @brief Valida o formato e a lógica da data.
    /// @details Verifica a sintaxe (DD-MMM-AAAA), a validade dos meses, o intervalo do ano
    /// e a existência do dia naquele mês específico.
    /// @param data A string da data a ser validada.
    /// @throw std::invalid_argument Se o formato estiver errado, o ano fora do intervalo ou a data não existir.
    ///
    void validar(std::string const &data);

public:
    ///
    /// @brief Construtor que inicializa a data com um valor.
    /// @param data String contendo a data (ex: "01-JAN-2024").
    /// @throw std::invalid_argument Se a data fornecida for inválida.
    ///
    Data(std::string data);

    ///
    /// @brief Define uma nova data.
    /// @param data A nova string de data.
    /// @throw std::invalid_argument Se a data for inválida ou estiver fora do intervalo permitido.
    ///
    void setData(std::string data);

    ///
    /// @brief Recupera a data armazenada.
    /// @return A string contendo a data no formato "DD-MMM-AAAA".
    ///
    std::string getData();
};

#endif // DATA_HPP
