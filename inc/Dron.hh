#ifndef DRON_HH
#define DRON_HH
#include "Graniastoslup.hh"
#include "Prostopadloscian.hh"
#include "InterRysowania.hh"

class Dron : public UkladW, public InterRysowania {
    private:
        Prostopadloscian korpus;
        array<Graniastoslup, 4> wirniki;
        double R;
    public:
    /**
     * @brief Konstruktor drona
     * 
     * @param _srodek srodek drona
     * @param _orientacja orientacja drona
     * @param rodzic wskaznik na poprzedni ukladW
     */
        Dron(Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic=nullptr);
    /**
     * @brief getter srodka drona
     * 
     * @return Wektor<3>
     */
        Wektor<3> get_srodek() const {return srodek;}
    /**
     * @brief getter dlugosci srodek-wierzcholek drona
     * 
     * @return double 
     */
        double get_R(){return R;}
    /**
     * @brief metoda 'gumka'
     * 
     * @param rysownik
     */
        void zmazuj(drawNS::Draw3DAPI *rysownik) override;
    /**
     * @brief metoda rysowania
     * 
     * @param rysownik 
     */
        void rysuj(drawNS::Draw3DAPI *rysownik) override;
    /**
     * @brief metoda poruszania sie w osi pionowej
     * 
     * @param wysokosc 
     */
        void wznies(double wysokosc);
    /**
     * @brief metoda poruszania w osi poziomej
     * 
     * @param odleglosc 
     */
        void lec(double odleglosc);
    /**
     * @brief metoda obrotu drona
     * 
     * @param kat 
     */
        void obroc(double kat);
    /**
     * @brief metoda krecaca wirnikami
     * 
     */
        void porusz_wirnikami();

        
        //void animacja(double wysokosc, double kat, double odleglosc, drawNS::Draw3DAPI *rysownik);
   
};

#endif