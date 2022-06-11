#ifndef INTERDRONA_HH
#define INTERDRONA_HH
#include "Dr3D_gnuplot_api.hh"

class InterDrona
{
public:
    virtual void lec(double odleglosc) = 0;
    virtual void obroc(double kat) = 0;
    virtual void wznies(double wysokosc) = 0;
    virtual void animacja(double wysokosc, double kat, double odleglosc, drawNS::Draw3DAPI *rysownik) = 0;
};


#endif