#include "ContainerQuarto.hpp"
#include "ContainerReserva.hpp"
#include "ContainerHotel.hpp"

ContainerQuarto* ContainerQuarto::instancia = nullptr;

ContainerQuarto* ContainerQuarto::getInstancia() {
    if (!instancia)
        instancia = new ContainerQuarto();
    return instancia;
}

bool ContainerQuarto::incluir(Quarto quarto){
    Hotel h;
    h.setCodigo(quarto.getCodigoHotel());
    if (!ContainerHotel::getInstancia()->pesquisar(&h))
        return false;

    std::string key = quarto.getCodigoHotel().getCodigo() + std::to_string(quarto.getNumero().getValor());
    return container.insert({key, quarto}).second;
}

bool ContainerQuarto::remover(const Codigo& codigoHotel, const Numero& numero){
    std::string key = codigoHotel.getCodigo() + std::to_string(numero.getValor());
    if (ContainerReserva::getInstancia()->quartoTemReserva(codigoHotel, numero))
        return false;
    auto it = container.find(key);
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerQuarto::pesquisar(Quarto* quarto){
    std::string key = quarto->getCodigoHotel().getCodigo() + std::to_string(quarto->getNumero().getValor());
    auto it = container.find(key);
    if(it != container.end()){
        *quarto = it->second;
        return true;
    }
    return false;
}

bool ContainerQuarto::atualizar(Quarto quarto){
    std::string key = quarto.getCodigoHotel().getCodigo() + std::to_string(quarto.getNumero().getValor());
    auto it = container.find(key);
    if(it != container.end()){
        it->second = quarto;
        return true;
    }
    return false;
}

int ContainerQuarto::quantidadeDeQuartos(const Codigo& codigoHotel){
    int count = 0;
    for(auto& par : container){
        if(par.second.getCodigoHotel().getCodigo() == codigoHotel.getCodigo())
            count++;
    }
    return count;
}

bool ContainerQuarto::existeReservaNoHotel(const Codigo& codigoHotel){
    return ContainerReserva::getInstancia()->hotelTemReserva(codigoHotel);
}

