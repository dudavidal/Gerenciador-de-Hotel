#include "CntrIUAutenticacao.hpp"
#include <iostream>

bool CntrIUAutenticacao::autenticar(EMAIL* email, Senha* senha) {
    if(!cntrLNAutenticacao) return false;
    return cntrLNAutenticacao->autenticar(*email, *senha);
}
