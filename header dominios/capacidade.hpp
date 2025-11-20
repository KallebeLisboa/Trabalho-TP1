#ifndef CAPACIDADE_HPP
#define CAPACIDADE_HPP

#include <stdexcept> // Necessário para usar std::invalid_argument

///
/// @brief Representa o domínio de Capacidade de acomodação.
///
/// @details Esta classe é responsável por armazenar e validar a capacidade de ocupação
/// de um quarto. Segundo as regras do sistema, a capacidade deve ser um valor específico
/// (1, 2, 3 ou 4).
///
class Capacidade {
private:
    int capacidade; ///< O atributo inteiro que armazena o valor da capacidade.

    ///
    /// @brief Valida o valor da capacidade segundo as regras de negócio.
    /// @param capacidade O valor a ser verificado.
    /// @throw std::invalid_argument Se o valor não for 1, 2, 3 ou 4.
    ///
    void validar(int const &capacidade);

public:
    ///
    /// @brief Construtor padrão que inicializa a classe com um valor.
    /// @param capacidade Valor inicial para a capacidade.
    /// @throw std::invalid_argument Se o valor inicial for inválido.
    ///
    Capacidade(int capacidade);

    ///
    /// @brief Define um novo valor para a capacidade.
    /// @param capacidade O novo valor a ser atribuído.
    /// @throw std::invalid_argument Se o valor fornecido não for 1, 2, 3 ou 4.
    ///
    void setCapacidade(int capacidade);

    ///
    /// @brief Recupera o valor atual da capacidade.
    /// @return O número inteiro representando a capacidade armazenada.
    ///
    int getCapacidade();
};

#endif // CAPACIDADE_HPP