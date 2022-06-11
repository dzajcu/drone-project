#ifndef OBIEKTY_HH
#define OBIEKTY_HH
#include "Graniastoslup.hh"
#include "Prostopadloscian.hh"
#include "InterRysowania.hh"
#include "InterKrajobrazu.hh"
class Plaskowyz : public UkladW, public InterRysowania, public InterKrajobrazu {
    private:
        int id_rysunku;
        vector<Wektor<3>> wierzcholki_gora;
        vector<Wektor<3>> wierzcholki_dol;
        int l_wierzcholkow;
        double wysokosc;
        double min, max;
    public:
    /**
     * @brief getter id plaskowyzu
     * 
     * @return id
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor Plaskowyzu
         * 
         * @param _wysokosc 
         * @param _srodek 
         * @param _orientacja 
         * @param wsk_na_poprz 
         */
        Plaskowyz(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *wsk_na_poprz=nullptr);
        /**
         * @brief metoda rysowania plaskowyzu
         * 
         * @param rysownik 
         */
        void rysuj(drawNS::Draw3DAPI *rysownik) override; 
        /**
         * @brief metoda zmazywania plaskowyzu
         * 
         * @param rysownik 
         */
        void zmazuj(drawNS::Draw3DAPI *rysownik) override;
        /**
         * @brief metoda sprawdzajaca czy dron jest nad obiektem
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_nad(shared_ptr<Dron> dron) override;
        /**
         * @brief metoda sprawdzajaca czy dron moze ladowac na obiekcie
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_ladowac(shared_ptr<Dron> dron) override;
        /**
         * @brief getter wysokosci
         * 
         * @return double 
         */
        double get_wysokosc() override {return wysokosc;} 
};


class PlaskowyzProst : public UkladW, public InterRysowania, public InterKrajobrazu {
    private:
        int id_rysunku;
        vector<Wektor<3>> wierzcholki_gora;
        vector<Wektor<3>> wierzcholki_dol;
        int l_wierzcholkow;
        double wysokosc;
        double _R;
    public:
    /**
     * @brief Getter id
     * 
     * @return id
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor Plaskowyzu Prostopadlosciennego
         * 
         * @param _wysokosc 
         * @param _srodek 
         * @param _orientacja 
         * @param wsk_na_poprz 
         */
        PlaskowyzProst(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *wsk_na_poprz=nullptr);
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
        /**
         * @brief metoda sprawdzajaca czy dron jest nad obiektem
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_nad(shared_ptr<Dron> dron) override{return false;}
        /**
         * @brief metoda sprawdzajaca czy dron moze ladowac na obiekcie
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_ladowac(shared_ptr<Dron> dron) override{return true;}
        /**
         * @brief getter wysokosci
         * 
         * @return double 
         */
        double get_wysokosc() override {return wysokosc;}
};


class Wzgorze : public UkladW, public InterRysowania, public InterKrajobrazu {
     private:
        int id_rysunku;
        vector<Wektor<3>> wierzcholki_dol;
        int l_wierzcholkow;
        double wysokosc;
        double min, max;
    public:
    /**
     * @brief Getter id
     * 
     * @return id
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor Wzgorza
         * 
         * @param _wysokosc 
         * @param _srodek 
         * @param _orientacja 
         * @param wsk_na_poprz 
         */
        Wzgorze(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *wsk_na_poprz=nullptr);
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
        /**
         * @brief metoda sprawdzajaca czy dron jest nad obiektem
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_nad(shared_ptr<Dron> dron) override;
        /**
         * @brief metoda sprawdzajaca czy dron moze ladowac na obiekcie
         * 
         * @param dron 
         * @return true 
         * @return false 
         */
        bool czy_ladowac(shared_ptr<Dron> dron) override; 
        /**
         * @brief Getter wysokosci
         * 
         * @return double 
         */
        double get_wysokosc() override {return wysokosc;}
};



#endif