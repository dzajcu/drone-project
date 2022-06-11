#ifndef INTERRYSOWANIA_HH
#define INTERRYSOWANIA_HH
#include "Dr3D_gnuplot_api.hh"

class InterRysowania {
    public:
    /**
     * @brief wirtualna metoda rysowania
     * 
     * @param rysownik 
     */
        virtual void rysuj(drawNS::Draw3DAPI *rysownik) = 0;
        /**
         * @brief wirtualna metoda zmazywania
         * 
         * @param rysownik 
         */
        virtual void zmazuj(drawNS::Draw3DAPI *rysownik) = 0;
};

#endif