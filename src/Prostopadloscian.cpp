#include "Prostopadloscian.hh"
#define BLAD 0.000000001

Prostopadloscian::Prostopadloscian(Wektor<3>w1, Wektor<3>w2, Wektor<3>w3, Wektor<3>w4, Wektor<3>w5, Wektor<3>w6, Wektor<3>w7, Wektor<3>w8, 
                                    Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
            srodek=_srodek;
            orientacja=_orientacja;
            wsk_na_poprz=rodzic;
            wierzcholki_gora[0]=w1;
            wierzcholki_gora[1]=w2;
            wierzcholki_gora[2]=w3;
            wierzcholki_gora[3]=w4;
            wierzcholki_dol[0]=w5;
            wierzcholki_dol[1]=w6;
            wierzcholki_dol[2]=w7;
            wierzcholki_dol[3]=w8;
            /*
            if(czy_to_Prostopadloscian()==false){
                cerr << " Wierzcholki nie tworza prostopadloscianu " << endl;
                exit(1);
            }
            */
}

void Prostopadloscian::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> gorne, dolne;
    vector<vector<drawNS::Point3D>> wierzcholki;
    UkladW uklad(srodek, orientacja, wsk_na_poprz);
    uklad.konwertuj_do_poprz();
    for(int i=0; i<4; i++){
        
        gorne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_gora[i])));
        dolne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_dol[i])));
    }
    wierzcholki.push_back(gorne);
    wierzcholki.push_back(dolne);
    id_rysunku=rysownik->draw_polyhedron(wierzcholki);
}

void Prostopadloscian::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}

double Prostopadloscian::dlugosc_boku(const Wektor<3> & arg1, const Wektor<3> & arg2)
{
    double dlugosc(sqrt(pow(arg1[0]-arg2[0], 2)+pow(arg1[1]-arg2[1], 2)+pow(arg1[2]-arg2[2], 2)));
    return dlugosc;
}


bool Prostopadloscian::czy_to_Prostopadloscian()
{
    if(fabs(dlugosc_boku(wierzcholki_gora[0], wierzcholki_gora[1]) - dlugosc_boku(wierzcholki_dol[2], wierzcholki_dol[3]))<=BLAD
    && fabs(dlugosc_boku(wierzcholki_gora[0], wierzcholki_gora[3]) - dlugosc_boku(wierzcholki_dol[1], wierzcholki_dol[2]))<=BLAD
    && fabs(dlugosc_boku(wierzcholki_gora[0], wierzcholki_dol[0]) - dlugosc_boku(wierzcholki_gora[2], wierzcholki_dol[2]))<=BLAD
    && fabs((wierzcholki_gora[0]-wierzcholki_gora[1])*(wierzcholki_gora[0]-wierzcholki_dol[0]))<=BLAD
    && fabs((wierzcholki_gora[0]-wierzcholki_gora[1])*(wierzcholki_gora[0]-wierzcholki_gora[3]))<=BLAD
    && fabs((wierzcholki_gora[0]-wierzcholki_gora[3])*(wierzcholki_gora[0]-wierzcholki_dol[0]))<=BLAD){
    return true;
    }
    else return false;
}

const Wektor<3> & Prostopadloscian::operator [] (int ind) const
{
    if ((ind >= 0 && ind <= 3)){
        return wierzcholki_gora[ind];
    }
    if ((ind >= 4 && ind <= 7)){
        return wierzcholki_dol[ind-4];
    }
    cerr << " Nie istnieje taki element ";
    exit(1);
}

