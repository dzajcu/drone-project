#include "macierz3D.hh"



template<int SIZE> MacierzObr<SIZE> MacierzObr<SIZE>::operator * (const MacierzObr<SIZE> & arg2)
{
    
    MacierzObr<SIZE> macierz;
    for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            macierz.tab[i][j]=0.0;
        }
    }
    for(int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            for(int k=0; k<SIZE; k++){
                    macierz.tab[i][j] += tab[i][k]*arg2.tab[k][j];
            }
        }
    }
    return macierz;
}

template<int SIZE> Wektor<SIZE> MacierzObr<SIZE>::operator * (const Wektor<SIZE> & arg2)
{
    Wektor<SIZE> wektor;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            wektor[i] += arg2[j]*tab[i][j];
        }
    }
   return wektor;
}

template<int SIZE> double MacierzObr<SIZE>::operator () (int wiersz, int kolumna) const
{
    double tmp;
    tmp=tab[wiersz][kolumna];
    return tmp;
}

template class MacierzObr <2>;
template class MacierzObr <3>;
