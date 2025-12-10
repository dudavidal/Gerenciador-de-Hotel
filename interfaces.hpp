#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "entidades.hpp"
#include <string>
using namespace std;

// ---------------------------------------------------------------------------
// INTERFACE DE AUTENTICAÇÃO
// ---------------------------------------------------------------------------
// --------- Interface LN Autenticacao ---------
class ILNAutenticacao {
public:
    virtual bool autenticar(const EMAIL &email, const Senha &senha) = 0;
    virtual ~ILNAutenticacao() {}
};

// --------- Interface IU Autenticacao ---------
class IUAutenticacao {
public:
    virtual bool autenticar(EMAIL* email, Senha* senha) = 0;
    virtual ~IUAutenticacao() {}
};

// ---------------------------------------------------------------------------
// INTERFACES DE APRESENTAÇÃO (CAMADA DE APRESENTAÇÃO)
// ---------------------------------------------------------------------------
class IApresentacaoPessoal {
public:
    virtual void criar() = 0;
    virtual void executar(const EMAIL&) = 0;
    virtual ~IApresentacaoPessoal() {}
};

// ---------------------------------------------------------------------------
// INTERFACES DE SERVIÇO (LÓGICA DE NEGÓCIO)
// ---------------------------------------------------------------------------
class IServicoPessoal {
public:
    virtual bool criar(Gerente) = 0;
    virtual bool ler(Gerente&) = 0;
    virtual bool editar(Gerente) = 0;
    virtual bool excluir(EMAIL) = 0;

    virtual ~IServicoPessoal() {}
};

#endif
