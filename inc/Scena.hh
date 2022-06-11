#include "Dron.hh"
#include "Obiekty.hh"


class Scena {
    private:
        vector<shared_ptr<InterRysowania>> rysuj;
        vector<shared_ptr<InterKrajobrazu>> el_krajobrazu;
    public:
        /**
         * @brief wskaznik do aktualnego drona
         * 
         */
        shared_ptr<Dron> dron;
        /**
         * @brief wskaznik na lacze do gnuplota
         * 
         */
        drawNS::Draw3DAPI *rysownik;
        /**
         * @brief konstruktor sceny
         * 
         * @param _rysownik 
         */
        Scena(drawNS::Draw3DAPI *_rysownik);
        /**
         * @brief metoda animacji
         * 
         * @param wysokosc 
         * @param kat 
         * @param odleglosc 
         * @param rysownik 
         */
        void animacja(double wysokosc, double kat, double odleglosc, drawNS::Draw3DAPI *rysownik);
        /**
         * @brief metoda dodawania obiektow na scene
         * 
         */
        void dodaj_obiekt();
        /**
         * @brief metoda usuwania ostatniego obiektu ze sceny
         * 
         */
        void usun_obiekt();
        /**
         * @brief metoda rysowania wszystkich elementow
         * 
         */
        void rysuj_wszystkie();
        /**
         * @brief metoda zmazywania wszystkich elementow
         * 
         */
        void zmazuj_wszystkie();

};