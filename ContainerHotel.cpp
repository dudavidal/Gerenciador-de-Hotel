#include "ContainerHotel.hpp"
#include "ContainerGerente.hpp"
#include "ContainerQuarto.hpp"

ContainerHotel* ContainerHotel::instancia = nullptr;

ContainerHotel* ContainerHotel::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerHotel();
    return instancia;
}

bool ContainerHotel::incluir(Hotel hotel){
    Gerente g;
    g.setEmail(hotel.getGerenteEmail());
    if (!ContainerGerente::getInstancia()->pesquisar(&g))
        return false;

    return container.insert({hotel.getCodigo().getCodigo(), hotel}).second;
}


bool ContainerHotel::remover(Codigo codigo){
    if (ContainerQuarto::getInstancia()->quantidadeDeQuartos(codigo) > 0)
        return false;
    if (ContainerQuarto::getInstancia()->existeReservaNoHotel(codigo))
        return false;
    auto it = container.find(codigo.getCodigo());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerHotel::pesquisar(Hotel* hotel){
    auto it = container.find(hotel->getCodigo().getCodigo());
    if(it != container.end()){
        *hotel = it->second;
        return true;
    }
    return false;
}

bool ContainerHotel::atualizar(Hotel hotel){
    auto it = container.find(hotel.getCodigo().getCodigo());
    if(it != container.end()){
        if (ContainerQuarto::getInstancia()->quantidadeDeQuartos(hotel.getCodigo()) == 0)
            return false;
        Gerente g;
        g.setEmail(hotel.getGerenteEmail());
        if (!ContainerGerente::getInstancia()->pesquisar(&g))
            return false;
        it->second = hotel;
        return true;
    }
    return false;
}

