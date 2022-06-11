#ifndef UKLADW_HH
#define UKLADW_HH
#include "macierz3D.hh"

class UkladW {
    protected:
        Wektor<3> srodek;
        MacierzObr<3> orientacja;
        UkladW * wsk_na_poprz;
    public:
    /**
     * @brief konstruktor domyslny ukladuW
     * 
     */
        UkladW() : srodek{0.0, 0.0, 0.0}, orientacja(), wsk_na_poprz() {}
        /**
         * @brief konstruktor ukladuW
         * 
         * @param _srodek 
         * @param _orientacja 
         * @param _wsk_na_poprz 
         */
        UkladW(Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *_wsk_na_poprz) :
            srodek(_srodek), orientacja(_orientacja), wsk_na_poprz(_wsk_na_poprz) {}
            /**
             * @brief metoda Obrotu
             * 
             * @param nowa 
             */
        void Obrot(MacierzObr<3> nowa){orientacja = orientacja * nowa;}
        /**
         * @brief metoda Translacji
         * 
         * @param nowy 
         */
        void Translacja(Wektor<3> nowy){srodek = srodek + nowy;}
        /**
         * @brief Metoda przeliczania ukladu
         * 
         * @param U 
         * @return UkladW 
         */

        UkladW przelicz_uklad(UkladW & U) const {return UkladW(U.srodek + U.orientacja * srodek, U.orientacja * orientacja, U.wsk_na_poprz);}
        /**
         * @brief metoda przeliczania punktu
         * 
         * @param wek 
         * @return Wektor<3> 
         */
        Wektor<3> przelicz_punkt(Wektor<3> wek) {return (srodek + orientacja * wek);}
        /**
         * @brief metoda konwertowania ukladuW wzgledem poprzednika
         * 
         */
        void konwertuj_do_poprz() { if(wsk_na_poprz != nullptr){ 
                                    (*this) = przelicz_uklad(*wsk_na_poprz);}; }
        /**
         * @brief metoda konwertowania ukladuW wzgledem bazowego
         * 
         */
        void konwertuj_do_bazy() { while(wsk_na_poprz != nullptr)
                                    { konwertuj_do_poprz();}; }
};



#endif