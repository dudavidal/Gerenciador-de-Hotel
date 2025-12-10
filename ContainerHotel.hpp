#ifndef CONTAINER_HOTEL_HPP_INCLUDED
#define CONTAINER_HOTEL_HPP_INCLUDED

#include "entidades.hpp"
#include <map>

class ContainerHotel {
private:
    std::map<std::string, Hotel> container;
    static ContainerHotel* instancia;

    ContainerHotel() {}

public:
    static ContainerHotel* getInstancia();

    bool incluir(Hotel hotel);
    bool remover(Codigo codigo);
    bool pesquisar(Hotel* hotel);
    bool atualizar(Hotel hotel);

    std::map<std::string, Hotel>& listarTodos() { return container; }
};

#endif

