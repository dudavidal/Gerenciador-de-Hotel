#ifndef CNTR_APRESENTACAO_PESSOAL_HPP_INCLUDED
#define CNTR_APRESENTACAO_PESSOAL_HPP_INCLUDED

#include "interfaces.hpp"
#include "entidades.hpp"
#include <iostream>

class CntrAprPessoal : public IApresentacaoPessoal {
private:
  IServicoPessoal *cntrLNPessoal;

public:
    void setCntrLNPessoal(IServicoPessoal*);

    void criar() override;
    void executar(const EMAIL&) override;
};

inline void CntrAprPessoal::setCntrLNPessoal(IServicoPessoal *cntr){
    this->cntrLNPessoal = cntr;
}

#endif
