#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH
#include <iostream>
#include "Wektor3D.hh"
#include <cmath>
#define PI 3.141592

template<int SIZE>
class MacierzObr {
    private:
        double tab[SIZE][SIZE];
    public:
    /**
     * @brief konstruktor bezparametryczny macierzy jednostkowej
     * 
     */
        MacierzObr<SIZE> (){
                for (int i=0; i<SIZE; i++){
                    for (int j=0; j<SIZE; j++){
                        if(i==j){ tab[i][j]=1; }
                             else tab[i][j]=0;
                    }
                }
        }
        /**
         * @brief konstruktor parametryczny macierzy
         * 
         * @param kat 
         * @param os_ukladu 
         */
        MacierzObr<SIZE> (double kat, char os_ukladu){
            if(SIZE==2){
                tab[0][0] = (cos((kat*PI) / 180)), 
                tab[0][1] = -(sin((kat*PI) / 180)), 
                tab[1][0] = (sin((kat*PI) / 180)),
                tab[1][1] = (cos((kat*PI) / 180));
            }
            if(SIZE==3){
                switch (os_ukladu){
                    case 'x':
                        tab[0][1] = tab[0][2] = tab[1][0] = tab[2][0] = 0,
                        tab[0][0] = 1,
                        tab[1][1] = (cos((kat*PI) / 180)),
                        tab[1][2] = -(sin((kat*PI) / 180)),
                        tab[2][1] = (sin((kat*PI) / 180)),
                        tab[2][2] = (cos((kat*PI) / 180));
                    break;

                    case 'y':
                        tab[0][1] = tab[1][0] = tab[1][2] = tab[2][1] = 0,
                        tab[1][1] = 1,
                        tab[0][0] = (cos((kat*PI) / 180)),
                        tab[2][0] = -(sin((kat*PI) / 180)),
                        tab[0][2] = (sin((kat*PI) / 180)),
                        tab[2][2] = (cos((kat*PI) / 180));
                    break;

                    case 'z':
                        tab[0][2] = tab[1][2] = tab[2][0] = tab[2][1] = 0,
                        tab[2][2] = 1,
                        tab[0][0] = (cos((kat*PI) / 180)),
                        tab[0][1] = -(sin((kat*PI) / 180)),
                        tab[1][0] = (sin((kat*PI) / 180)),
                        tab[1][1] = (cos((kat*PI) / 180));
                    break;

                    default:
                        cerr << "Bledna opcja obrotu, dostepne warianty: x, y, z" << endl;
                    break;
                }
            }
        }
    /**
     * @brief metoda mnozenia wektora i macierzy
     * 
     * @param arg2 
     * @return MacierzObr<SIZE> 
     */
    MacierzObr<SIZE> operator * (const MacierzObr<SIZE> & arg2);
    /**
     * @brief metoda mnozenia wektorow
     * 
     * @param arg2 
     * @return Wektor<SIZE> 
     */
    Wektor<SIZE> operator * (const Wektor<SIZE> & arg2);
    /**
     * @brief operator indeksujacy
     * 
     * @param wiersz 
     * @param kolumna 
     * @return double 
     */
    double operator () (int wiersz, int kolumna) const;
};

#endif