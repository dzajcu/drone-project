#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH
#include <iostream>
#include <vector>
#include "Dr3D_gnuplot_api.hh"

using namespace std;

template<int SIZE>
class Wektor {
    private:
    vector<double> xyz;
    inline static int ile_obecnie = 0;
    inline static int ile_wszystkich = 0;
    public:
    /**
     * @brief konstruktor domyslny wektora
     * 
     */
    Wektor<SIZE>() {this->xyz = vector<double>(SIZE, 0); ile_obecnie++; ile_wszystkich++;}
    /**
     * @brief konstruktor inicializujjacy
     * 
     * @param arg 
     */
    Wektor<SIZE>(initializer_list<double> arg) : xyz{arg} {ile_obecnie++; ile_wszystkich++;}
    /**
     * @brief konstruktor kopiujacy wektora
     * 
     * @param inny 
     */
    Wektor<SIZE>(const Wektor & inny) : xyz(inny.xyz) {ile_obecnie++; ile_wszystkich++;}
    /**
     * @brief destruktor wektora
     * 
     */
    ~Wektor<SIZE>(){ile_obecnie--;}

    /**
     * @brief getter obecnych wektorow
     * 
     * @return int 
     */
    inline static int get_obecnie(){return ile_obecnie;}
    /**
     * @brief Getter wszystkich wektorow
     * 
     * @return int 
     */
    inline static int get_wszystkie(){return ile_wszystkich;}
    /**
     * @brief metoda dodawania wektorow
     * 
     * @param arg2 
     * @return Wektor<SIZE> 
     */
    Wektor<SIZE> operator + (const Wektor<SIZE> & arg2) const;
    /**
     * @brief metoda odejmowania wektorow
     * 
     * @param arg2 
     * @return Wektor<SIZE> 
     */
    Wektor<SIZE> operator - (const Wektor<SIZE> & arg2) const;
    /**
     * @brief metoda mnozenia
     * 
     * @param arg2 
     * @return double 
     */
    double operator * (const Wektor<SIZE> & arg2) const; 

    /**
     * @brief operator indeksujacy
     * 
     * @param ind 
     * @return const double& 
     */
    const double & operator [] (int ind) const;
    /**
     * @brief operator indeksujacy
     * 
     * @param ind 
     * @return double& 
     */
    double & operator [] (int ind);


};

    /**
     * @brief konwertowanie punktu na potrzeby API
     * 
     * @param arg2 
     * @return drawNS::Point3D 
     */
    drawNS::Point3D konwertuj(const Wektor<3> & arg2);
    /**
     * @brief operator strumienia wyjsciowego
     * 
     * @tparam SIZE 
     * @param strm 
     * @param wektor 
     * @return ostream& 
     */
    template<int SIZE> ostream & operator << (ostream & strm, const Wektor<SIZE> &wektor);

#endif