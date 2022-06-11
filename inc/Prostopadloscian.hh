#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH
#include "macierz3D.hh"
#include <array>
#include "UkladW.hh"
#include "InterRysowania.hh"

class Prostopadloscian : public UkladW, public InterRysowania {
    private:
        int id_rysunku;
        array<Wektor<3>, 4> wierzcholki_gora;
        array<Wektor<3>, 4> wierzcholki_dol;
    public:
    /**
     * @brief Getter id
     * 
     * @return id
     */
        int get_id() const {return id_rysunku;}
        /**
         * @brief konstruktor bezparametryczny prostopadloscianu
         * 
         */
        Prostopadloscian()=default;
        /**
         * @brief konstruktor parametryczny
         * 
         * @param _srodek 
         * @param _orientacja 
         * @param wsk_na_poprz 
         */
        Prostopadloscian(Wektor<3>w1, Wektor<3>w2, Wektor<3>w3, Wektor<3>w4, Wektor<3>w5, Wektor<3>w6, Wektor<3>w7, Wektor<3>w8,
                         Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *wsk_na_poprz);
        /**
         * @brief metoda rysowania prostopadloscianu
         * 
         * @param rysownik 
         */
        void rysuj(drawNS::Draw3DAPI *rysownik) override;
        /**
         * @brief metoda zmazywania prostopadloscianu
         * 
         * @param rysownik 
         */
        void zmazuj(drawNS::Draw3DAPI *rysownik) override;
        /**
         * @brief metoda wyliczajaca dlugosc boku
         * 
         * @param arg1 
         * @param arg2 
         * @return double 
         */
        double dlugosc_boku(const Wektor<3> & arg1, const Wektor<3> & arg2);
        /**
         * @brief metoda sprawdzajaca czy obiekt jest prostopadloscianem
         * 
         * @return true 
         * @return false 
         */
        bool czy_to_Prostopadloscian();
        /**
         * @brief operator indeksujacy
         * 
         * @param ind 
         * @return const Wektor<3>& 
         */
        const Wektor<3> & operator [] (int ind) const;
};

#endif