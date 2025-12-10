#ifndef CONTAINER_QUARTO_HPP_INCLUDED
#define CONTAINER_QUARTO_HPP_INCLUDED

#include "entidades.hpp"
#include <map>

class ContainerQuarto {
private:
    std::map<std::string, Quarto> container;
    static ContainerQuarto* instancia;

    ContainerQuarto() {}

public:
    static ContainerQuarto* getInstancia();

    bool incluir(Quarto quarto);
    bool remover(const Codigo& codigoHotel, const Numero& numero);
    bool pesquisar(Quarto *quarto);
    bool atualizar(Quarto quarto);

    int quantidadeDeQuartos(const Codigo& codigoHotel);
    bool existeReservaNoHotel(const Codigo& codigoHotel);

    std::map<std::string, Quarto>& listarTodos() { return container; }
};

#endif
