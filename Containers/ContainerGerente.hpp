#ifndef CONTAINER_GERENTE_HPP_INCLUDED
#define CONTAINER_GERENTE_HPP_INCLUDED

#include "entidades.hpp"
#include "ContainerHotel.hpp"
#include <map>
#include <vector>

class ContainerGerente {
private:
    std::map<std::string, Gerente> container;
    static ContainerGerente* instancia;
    ContainerGerente() {};

public:
    static ContainerGerente* getInstancia();

    bool incluir(Gerente gerente);
    bool remover(EMAIL email);
    bool pesquisar(Gerente* gerente);
    bool atualizar(Gerente gerente);
    bool gerenteTemHotel(EMAIL emailGerente);
};

#endif
