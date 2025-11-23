#ifndef RESERVA_HPP
#define RESERVA_HPP

// Inclusão das classes de domínio que serão atributos
#include "../header dominios/data.hpp"
#include "../header dominios/dinheiro.hpp"
#include "../header dominios/codigo.hpp"
#include "../header dominios/email.hpp"
#include "../header dominios/numero.hpp"


class Reserva {
private:
    // Atributos são instâncias das classes de Domínio
    Data chegada;
    Data partida;
    Dinheiro valor;
    Codigo codigo; // <<PK>> - Chave Primária

    Numero numeroQuarto;   // PK do Quarto ao qual a reserva está associada
    Email emailHospede;    // PK do Hóspede ao qual a reserva está associada
    Codigo codigoHotel;    // PK do Hotel ao qual a reserva está associada

public:
    // Construtor
    Reserva(const Data& chegada, const Data& partida, const Dinheiro& valor, const Codigo& codigo, const Email& emailHospede, const Numero& numeroQuarto, const Codigo& codigoHotel);
    // Métodos Get (Para acesso aos atributos)
    Data getChegada() const;
    Data getPartida() const;
    Dinheiro getValor() const;
    Codigo getCodigo() const;
    Email getEmailHospede() const;
    Numero getNumeroQuarto() const;
    Codigo getCodigoHotel() const;


    // Métodos Set (Para modificar os atributos)
    // Não é possível editar dado que identifica registro (chave primária).
    void setChegada(const Data& chegada);
    void setPartida(const Data& partida);
    void setValor(const Dinheiro& valor);
    void setEmailHospede(const Email& emailHospede);
    void setNumeroQuarto(const Numero& numeroQuarto);
    void setCodigoHotel(const Codigo& codigoHotel);

};

#endif // RESERVA_HPP
