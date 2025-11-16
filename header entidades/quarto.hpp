#ifndef QUARTO_HPP
#define QUARTO_HPP

// Inclusão das classes de Domínio necessárias (assumindo o caminho 'header dominios/')
#include "header dominios/codigo.hpp"      // Para o codigoHotel (FK do Hotel)
#include "header dominios/numero.hpp"      // Para o atributo número
#include "header dominios/capacidade.hpp"  // Para o atributo capacidade
#include "header dominios/dinheiro.hpp"    // Para o atributo diaria
#include "header dominios/ramal.hpp"       // Para o atributo ramal

class Quarto {
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria; 
    Ramal ramal;
    Codigo codigoHotel; // Referência ao Hotel (Chave Estrangeira)

public:
    // Construtor completo
    Quarto(const Codigo& codigoHotel, const Numero& numero, const Capacidade& capacidade, const Dinheiro& diaria, const Ramal& ramal);

    // Métodos Get
    Codigo getCodigoHotel() const;
    Numero getNumero() const;
    Capacidade getCapacidade() const;
    Dinheiro getDiaria() const;
    Ramal getRamal() const;

    // Métodos Set
    void setCodigoHotel(const Codigo& codigoHotel);
    void setNumero(const Numero& numero);
    void setCapacidade(const Capacidade& capacidade);
    void setDiaria(const Dinheiro& diaria);
    void setRamal(const Ramal& ramal);
};

#endif // QUARTO_HPP