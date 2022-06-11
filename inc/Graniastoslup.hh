#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include "UkladW.hh"
#include "InterRysowania.hh"

class Graniastoslup : public UkladW, public InterRysowania {
    private:
        int id_rysunku;
        array<Wektor<3>, 6> wierzcholki_gora;
        array<Wektor<3>, 6> wierzcholki_dol;
    public:
    /**
     * @brief getter id
     * 
     * @return int 
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor bezparametryczny graniastoslupa
         * 
         */
        Graniastoslup()=default;
        /**
         * @brief konstruktor parametryczny graniastoslupa
         * 
         * @param _wysokosc 
         * @param _R 
         * @param _srodek 
         * @param _orientacja 
         * @param rodzic 
         */
        Graniastoslup(double _wysokosc, double _R, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic);
        /**
         * @brief metoda rysowania
         * 
         * @param rysownik 
         */
        void rysuj(drawNS::Draw3DAPI *rysownik) override;
        /**
         * @brief metoda zmazywania
         * 
         * @param rysownik 
         */
        void zmazuj(drawNS::Draw3DAPI *rysownik) override;
};



#endif