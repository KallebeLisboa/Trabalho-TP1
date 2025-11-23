#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>

class Email {
private:
    std::string email;

    // Declaração do método de validação
    void validar(std::string const &email);

public:
    // Construtor
    Email(std::string email);

    // Método set
    void setEmail(std::string email);

    // Método get
    std::string getEmail();
};

#endif
