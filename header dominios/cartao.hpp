#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>
#include <stdexcept>
#include <cctype> // Para usar isdigit

///
/// @brief Representa o domínio de número de Cartão de Crédito.
///
/// @details Esta classe é responsável por armazenar e validar números de cartão de crédito.
/// As regras de validação aplicadas são:
/// 1. O número deve conter exatamente 16 dígitos numéricos.
/// 2. O número deve ser válido segundo o algoritmo de Luhn (dígito verificador).
///
class Cartao {
private:
    std::string cartao; ///< Armazena a string contendo os 16 dígitos do cartão.

    // Funções auxiliares para o algoritmo de Luhn

    ///
    /// @brief Auxiliar para o algoritmo de Luhn: processa um dígito específico.
    /// @details Se o dobro do dígito for maior que 9, soma os dígitos do resultado.
    /// @param numero O dígito a ser processado.
    /// @return O valor processado para a soma.
    ///
    int pegarDigito(const int numero);

    ///
    /// @brief Soma os dígitos nas posições pares (contando da direita para a esquerda).
    /// @param cartao A string do cartão.
    /// @return A soma calculada.
    ///
    int somarDigitosPares(const std::string cartao);

    ///
    /// @brief Soma os dígitos nas posições ímpares.
    /// @param cartao A string do cartão.
    /// @return A soma calculada.
    ///
    int somarDigitosImpares(const std::string cartao);

    ///
    /// @brief Valida o formato e a integridade do número do cartão.
    /// @details Verifica se há 16 dígitos e aplica o algoritmo de Luhn.
    /// @param cartao A string a ser validada.
    /// @throw std::invalid_argument Se o tamanho for diferente de 16, se contiver não-dígitos ou falhar no teste de Luhn.
    ///
    void validar(std::string const &cartao);

public:
    ///
    /// @brief Construtor que inicializa o cartão com um número.
    /// @param cartao String contendo o número do cartão.
    /// @throw std::invalid_argument Se o cartão fornecido for inválido.
    ///
    Cartao(std::string cartao);

    ///
    /// @brief Define um novo número de cartão.
    /// @param cartao A string contendo o novo número.
    /// @throw std::invalid_argument Se o formato for inválido (não numérico, tamanho errado) ou inválido por Luhn.
    ///
    void setCartao(std::string cartao);

    ///
    /// @brief Recupera o número do cartão armazenado.
    /// @return A string com os 16 dígitos do cartão.
    ///
    std::string getCartao();
};

#endif // CARTAO_HPP