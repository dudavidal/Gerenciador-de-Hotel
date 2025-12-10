#ifndef CNTRMAI_HPP_INCLUDED
#define CNTRMAI_HPP_INCLUDED

#include "CntrAprPessoal.hpp"
#include "IAutenticacao.hpp"

class CntrMai {
private:
    IAutenticacao* ctrlAutenticacao;
    CntrAprPessoal* ctrlGerente;

public:
    void setCtrlAutenticacao(IAutenticacao* a) { ctrlAutenticacao = a; }
    void setCtrlGerente(CntrAprPessoal* g) { ctrlGerente = g; }

    void executar();
};

#endif

