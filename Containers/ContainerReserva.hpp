#ifndef CONTAINER_RESERVA_HPP_INCLUDED
#define CONTAINER_RESERVA_HPP_INCLUDED

#include "entidades.hpp"
#include <map>

class ContainerReserva {
private:
    std::map<std::string, Reserva> container;
    static ContainerReserva* instancia;

    ContainerReserva() {}

public:
    static ContainerReserva* getInstancia();

    bool incluir(Reserva reserva);
    bool remover(const Codigo& codigoHotel, const Numero& numeroQuarto, const Codigo& codigoReserva);
    bool pesquisar(Reserva* reserva);
    bool atualizar(Reserva reserva);

    bool quartoTemReserva(const Codigo& codigoHotel, const Numero& numeroQuarto);
    bool hotelTemReserva(const Codigo& codigoHotel);
    bool hospedeTemReserva(const EMAIL& emailHospede);

    bool reservaConflita(const Codigo& codigoHotel, const Numero& numeroQuarto,
                         const Data& inicio, const Data& fim);

    std::map<std::string, Reserva>& listarTodos() { return container; }
};

#endif

