#include "Wektor3D.hh" 

template<int SIZE> Wektor<SIZE> Wektor<SIZE>::operator + (const Wektor<SIZE> & arg2) const
{
    Wektor<SIZE> wektor;
        for (int i = 0; i<SIZE; ++i){
            wektor.xyz[i] = xyz[i] + arg2.xyz[i];
        }
    return wektor;
}

template<int SIZE> Wektor<SIZE> Wektor<SIZE>::operator - (const Wektor<SIZE> & arg2) const
{
    Wektor<SIZE> wektor;
        for (int i = 0; i<SIZE; ++i){
            wektor.xyz[i] = xyz[i] - arg2.xyz[i];
        }
    return wektor;
}

template<int SIZE> double Wektor<SIZE>::operator * (const Wektor<SIZE> & arg2) const
{ 
    double wynik;
        for (int i = 0; i<SIZE; ++i){
            wynik += xyz[i]*arg2.xyz[i];
        }
    return wynik;
}

template<int SIZE> const double & Wektor<SIZE>::operator [] (int ind) const
{
        if(ind < 0 && ind > SIZE){
            cerr << " Nie istnieje taki element ";
            exit(1);
        }
        return xyz[ind];
}

template<int SIZE> double & Wektor<SIZE>::operator [] (int ind)
{
        if(ind < 0 && ind > SIZE){
            cerr << " Nie istnieje taki element ";
            exit(1);
        }
        return xyz[ind];
}


template<int SIZE> ostream & operator << (ostream & strm, const Wektor<SIZE> &wektor)
{
    strm << "[";
    for(int i=0; i<SIZE-1; i++){
        strm << wektor[i];
        strm << ", ";
    }
    strm << wektor[SIZE-1];
    strm << "]"; 
    return strm; 
}

drawNS::Point3D konwertuj(const Wektor<3> & arg2)
{
    drawNS::Point3D punkt(arg2[0], arg2[1], arg2[2]);
    return punkt;
}

template class Wektor<2>;
template class Wektor<3>;
template class Wektor<6>;

template ostream & operator << (ostream & strm, const Wektor<2> &wektor);
template ostream & operator << (ostream & strm, const Wektor<3> &wektor);
template ostream & operator << (ostream & strm, const Wektor<6> &wektor);