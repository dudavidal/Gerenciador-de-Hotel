#ifndef CONTAINER_HOSPEDE_HPP_INCLUDED
#define CONTAINER_HOSPEDE_HPP_INCLUDED

#include "entidades.hpp"
#include <map>

class ContainerHospede {
private:
    std::map<std::string, Hospede> container;
    static ContainerHospede* instancia;

    ContainerHospede() {}

public:
    static ContainerHospede* getInstancia();

    bool incluir(Hospede hospede);
    bool remover(const EMAIL& email);
    bool pesquisar(Hospede* hospede);
    bool atualizar(Hospede hospede);

    bool hospedeTemReserva(const EMAIL& email);

    std::map<std::string, Hospede>& listarTodos() { return container; }
};

#endif
