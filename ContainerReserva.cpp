#include "ContainerReserva.hpp"
#include "ContainerHospede.hpp"
#include "ContainerQuarto.hpp"

ContainerReserva* ContainerReserva::instancia = nullptr;

ContainerReserva* ContainerReserva::getInstancia() {
    if (!instancia)
        instancia = new ContainerReserva();
    return instancia;
}

bool ContainerReserva::incluir(Reserva reserva){
    // Verifica se hóspede existe
    Hospede h;
    h.setEmail(reserva.getEmailHospede());
    if (!ContainerHospede::getInstancia()->pesquisar(&h))
        return false;

    // Verifica conflito de datas
    if (reservaConflita(reserva.getCodigoHotel(), reserva.getNumeroQuarto(),
                        reserva.getChegada(), reserva.getPartida()))
        return false;

    std::string key = reserva.getCodigo().getCodigo(); // PK da reserva
    return container.insert({key, reserva}).second;
}

bool ContainerReserva::remover(const Codigo& codigoHotel, const Numero& numeroQuarto, const Codigo& codigoReserva){
    std::string key = codigoReserva.getCodigo();
    auto it = container.find(key);
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerReserva::pesquisar(Reserva* reserva){
    std::string key = reserva->getCodigo().getCodigo();
    auto it = container.find(key);
    if(it != container.end()){
        *reserva = it->second;
        return true;
    }
    return false;
}

bool ContainerReserva::atualizar(Reserva reserva){
    std::string key = reserva.getCodigo().getCodigo();
    auto it = container.find(key);
    if(it != container.end()){
        // Verifica conflito de datas
        if (reservaConflita(reserva.getCodigoHotel(), reserva.getNumeroQuarto(),
                            reserva.getChegada(), reserva.getPartida()))
            return false;

        it->second = reserva;
        return true;
    }
    return false;
}

bool ContainerReserva::quartoTemReserva(const Codigo& codigoHotel, const Numero& numeroQuarto){
    for(auto& par : container){
        Reserva& r = par.second;
        if(r.getCodigoHotel().getCodigo() == codigoHotel.getCodigo() &&
           r.getNumeroQuarto().getValor() == numeroQuarto.getValor())
            return true;
    }
    return false;
}

bool ContainerReserva::hotelTemReserva(const Codigo& codigoHotel){
    for(auto& par : container){
        Reserva& r = par.second;
        if(r.getCodigoHotel().getCodigo() == codigoHotel.getCodigo())
            return true;
    }
    return false;
}

bool ContainerReserva::hospedeTemReserva(const EMAIL& emailHospede){
    for(auto& par : container){
        Reserva& r = par.second;
        if(r.getEmailHospede().getEmail() == emailHospede.getEmail())
            return true;
    }
    return false;
}

bool ContainerReserva::reservaConflita(const Codigo& codigoHotel, const Numero& numeroQuarto,
                                       const Data& inicio, const Data& fim){
    for(auto& par : container){
        Reserva& r = par.second;
        if(r.getCodigoHotel().getCodigo() == codigoHotel.getCodigo() &&
           r.getNumeroQuarto().getValor() == numeroQuarto.getValor()){

            const Data& rInicio = r.getChegada();
            const Data& rFim    = r.getPartida();

            // Checa se fim < rInicio
            bool fimAntes = (fim.getAno() < rInicio.getAno()) ||
                            (fim.getAno() == rInicio.getAno() && fim.getMes() < rInicio.getMes()) ||
                            (fim.getAno() == rInicio.getAno() && fim.getMes() == rInicio.getMes() && fim.getDia() < rInicio.getDia());

            // Checa se inicio > rFim
            bool inicioDepois = (inicio.getAno() > rFim.getAno()) ||
                                (inicio.getAno() == rFim.getAno() && inicio.getMes() > rFim.getMes()) ||
                                (inicio.getAno() == rFim.getAno() && inicio.getMes() == rFim.getMes() && inicio.getDia() > rFim.getDia());

            // Se não termina antes nem começa depois, há conflito
            if (!(fimAntes || inicioDepois))
                return true;
        }
    }
    return false;
}
