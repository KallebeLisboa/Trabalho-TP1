#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>

class Email {
private:
    std::string email;

    // Declaração do método de validação
    void validar(const std::string& valorEmail);

public:
    // Construtor
    Email(const std::string& valorEmail);

    // Método set
    void setEmail(const std::string& valorEmail);

    // Método get
    std::string getEmail() const;
};

#endif
