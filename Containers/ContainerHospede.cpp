#include "ContainerHospede.hpp"
#include "ContainerReserva.hpp"

ContainerHospede* ContainerHospede::instancia = nullptr;

ContainerHospede* ContainerHospede::getInstancia() {
    if (!instancia)
        instancia = new ContainerHospede();
    return instancia;
}

bool ContainerHospede::incluir(Hospede hospede){
    return container.insert({hospede.getEmail().getEmail(), hospede}).second;
}

bool ContainerHospede::remover(const EMAIL& email){
    if (hospedeTemReserva(email))
        return false;

    auto it = container.find(email.getEmail());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerHospede::pesquisar(Hospede* hospede){
    auto it = container.find(hospede->getEmail().getEmail());
    if(it != container.end()){
        *hospede = it->second;
        return true;
    }
    return false;
}

bool ContainerHospede::atualizar(Hospede hospede){
    auto it = container.find(hospede.getEmail().getEmail());
    if(it != container.end()){
        it->second = hospede;
        return true;
    }
    return false;
}

bool ContainerHospede::hospedeTemReserva(const EMAIL& email){
    return ContainerReserva::getInstancia()->hospedeTemReserva(email);
}

