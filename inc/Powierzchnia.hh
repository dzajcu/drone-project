#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "Dr3D_gnuplot_api.hh"
#include "InterRysowania.hh"
#include "Wektor3D.hh"

class Powierzchnia : public InterRysowania {
    private:
        double wysokosc;
        int id_rysunku;
    public:
    /**
     * @brief Get the id object
     * 
     * @return id_rysunku
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor powierzchni
         * 
         * @param _wysokosc 
         */
        Powierzchnia(double _wysokosc) : wysokosc(_wysokosc) {}
        /**
         * @brief metoda rysowania powierzchni
         * 
         * @param rysownik 
         */
        void rysuj(drawNS::Draw3DAPI *rysownik) override;
        /**
         * @brief metoda zmazywania powierzchni
         * 
         * @param rysownik 
         */
        void zmazuj(drawNS::Draw3DAPI *rysownik) override;
};

#endif