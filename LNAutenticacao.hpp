#ifndef LNAUTENTICACAO_HPP
#define LNAUTENTICACAO_HPP

#include "interfaces.hpp"
#include "ContainerGerente.hpp"
#include "entidades.hpp"

class LNAutenticacao : public ILNAutenticacao {
private:
    ContainerGerente* container;

public:
    LNAutenticacao(ContainerGerente* c) : container(c) {}
    bool autenticar(const EMAIL &email, const Senha &senha) override;
};

#endif
