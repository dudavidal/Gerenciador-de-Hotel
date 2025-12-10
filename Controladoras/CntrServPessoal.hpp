#ifndef CNTRSERVPESSOAL_HPP_INCLUDED
#define CNTRSERVPESSOAL_HPP_INCLUDED

#include "interfaces.hpp"
#include "entidades.hpp"
#include "ContainerGerente.hpp"

class CntrServPessoal : public IServicoPessoal {
public:
    bool criar(Gerente) override;
    bool ler(Gerente&) override;
    bool editar(Gerente) override;
    bool excluir(EMAIL) override;
};

#endif
