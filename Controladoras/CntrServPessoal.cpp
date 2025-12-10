#include "CntrServPessoal.hpp"
#include "ContainerGerente.hpp"

bool CntrServPessoal::criar(Gerente novo) {
    return ContainerGerente::getInstancia()->incluir(novo);
}

bool CntrServPessoal::ler(Gerente &g) {
    return ContainerGerente::getInstancia()->pesquisar(&g);
}

bool CntrServPessoal::editar(Gerente g) {
    return ContainerGerente::getInstancia()->atualizar(g);
}

bool CntrServPessoal::excluir(EMAIL email) {
    return ContainerGerente::getInstancia()->remover(email);
}

