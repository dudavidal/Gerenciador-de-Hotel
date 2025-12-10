#ifndef CNTRIUAUTENTICACAO_HPP
#define CNTRIUAUTENTICACAO_HPP

#include "interfaces.hpp"
#include "entidades.hpp"

class CntrIUAutenticacao : public IUAutenticacao {
private:
    ILNAutenticacao* cntrLNAutenticacao;

public:
    void setCntrLNAutenticacao(ILNAutenticacao* cntr) { cntrLNAutenticacao = cntr; }
    bool autenticar(EMAIL* email, Senha* senha) override;
};

#endif
