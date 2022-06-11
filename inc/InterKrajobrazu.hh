#ifndef INTERKRAJOBRAZU_HH
#define INTERKRAJOBRAZU_HH
#include "Dron.hh"

class InterKrajobrazu
{
public:
    /**
     * @brief wirtualna metoda czy_nad
     * 
     * @param dron 
     * @return true 
     * @return false 
     */
    virtual bool czy_nad(shared_ptr<Dron> dron) = 0;
    /**
     * @brief wirtualna metoda czy_ladowac
     * 
     * @param dron 
     * @return true 
     * @return false 
     */
    virtual bool czy_ladowac(shared_ptr<Dron> dron) = 0;
    /**
     * @brief wirtualny getter wysokosci obiektow
     * 
     * @return double 
     */
    virtual double get_wysokosc() = 0;
};


#endif