#include "ContainerGerente.hpp"
#include <vector>

ContainerGerente* ContainerGerente::instancia = nullptr;

ContainerGerente* ContainerGerente::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerGerente();
    return instancia;
}

bool ContainerGerente::incluir(Gerente gerente){
    return container.insert(
        std::make_pair(gerente.getEmail().getEmail(), gerente)
    ).second;
}

bool ContainerGerente::gerenteTemHotel(EMAIL emailGerente){
    ContainerHotel* contHotel = ContainerHotel::getInstancia();

    auto& lista = contHotel->listarTodos();

    for (const auto& par : lista) {
        const Hotel& h = par.second;

        if (h.getGerenteEmail().getEmail() == emailGerente.getEmail()) {
            return true;
        }
    }

    return false;
}



bool ContainerGerente::remover(EMAIL email){
    if (gerenteTemHotel(email)) {
        return false;
    }

    auto it = container.find(email.getEmail());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}


bool ContainerGerente::pesquisar(Gerente* gerente){
    auto it = container.find(gerente->getEmail().getEmail());
    if(it != container.end()){
        *gerente = it->second;
        return true;
    }
    return false;
}

bool ContainerGerente::atualizar(Gerente gerente){
    auto it = container.find(gerente.getEmail().getEmail());
    if(it != container.end()){
        it->second = gerente;
        return true;
    }
    return false;
}

