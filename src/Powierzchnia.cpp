#include "Powierzchnia.hh"

void Powierzchnia::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> punkty;
    vector<vector<drawNS::Point3D>> siatka;
    double x=100.0;
    double y=100.0;
    double gestosc=20;
    double rozmiar=200/gestosc + 1;
    for(int i=0; i<rozmiar; i++){
        punkty.push_back(konwertuj(Wektor<3> {x, y, wysokosc}));
        x-=gestosc;
        if(x==-100){ y-=gestosc; x=100; i=0; }
        if(y==-100){ x=100, y=100; break; }
    }

    for(int j=0; j<rozmiar; j++){
        punkty.push_back(konwertuj(Wektor<3> {x, y, wysokosc}));
        y-=gestosc;
        if(y==-100){ x-=gestosc; y=100; j=0; }
        if(x==-100){ break; }
    }
    siatka.push_back(punkty);
    id_rysunku=rysownik->draw_polyhedron(siatka);
}

void Powierzchnia::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}