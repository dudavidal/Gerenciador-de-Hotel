#include "LNAutenticacao.hpp"

bool LNAutenticacao::autenticar(const EMAIL &email, const Senha &senha) {
    Gerente g;
    g.setEmail(email);

    if(container->pesquisar(&g)) {
        if(g.getSenha().getValor() == senha.getValor())
            return true;
    }

    return false;
}

