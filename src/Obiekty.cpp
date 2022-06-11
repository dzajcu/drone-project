#include "Obiekty.hh"
#include <random>
#include <algorithm>
#include <iterator>

Plaskowyz::Plaskowyz(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
    srodek=_srodek;
    orientacja=_orientacja;
    wsk_na_poprz=rodzic;
    wysokosc =_wysokosc;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(5, 7);
    double _R;
    max=0; 
    min=100;
    l_wierzcholkow = distribution(generator);
    for(int i=0; i<l_wierzcholkow; i++){
        MacierzObr<3> obrot(i*(360/l_wierzcholkow), 'z');
        _R = 3*distribution(generator);
        if(max<_R){max=_R;}
        if(min>_R){min=_R;}
        wierzcholki_dol.push_back(obrot*Wektor<3> {_R, 0, 0});
        wierzcholki_gora.push_back(wierzcholki_dol[i]+Wektor<3> {0, 0, wysokosc});
    } 
} 

void Plaskowyz::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> gorne, dolne;
    vector<vector<drawNS::Point3D>> wierzcholki;
    UkladW uklad(srodek, orientacja, wsk_na_poprz);
    uklad.konwertuj_do_poprz();
    for(int i=0; i<l_wierzcholkow; i++){
        gorne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_gora[i])));
        dolne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_dol[i])));
    }
    wierzcholki.push_back(gorne);
    wierzcholki.push_back(dolne);
    id_rysunku=rysownik->draw_polyhedron(wierzcholki);
}

void Plaskowyz::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}

bool Plaskowyz::czy_nad(shared_ptr<Dron> dron)
{
    Wektor<3> sr_drona=dron->get_srodek();
    if(sqrt(pow(srodek[0]-sr_drona[0], 2)+pow(srodek[1]-sr_drona[1], 2)) <= dron->get_R()+max) {return true;}
    else return false;
}

bool Plaskowyz::czy_ladowac(shared_ptr<Dron> dron)
{
    Wektor<3> sr_drona=dron->get_srodek();
    if(sqrt(pow(srodek[0]-sr_drona[0], 2)+pow(srodek[1]-sr_drona[1], 2)) <= min-dron->get_R()) {return true;}
    else return false;
}




PlaskowyzProst::PlaskowyzProst(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
    srodek=_srodek;
    orientacja=_orientacja;
    wsk_na_poprz=rodzic;
    wysokosc =_wysokosc;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(19,24);
    l_wierzcholkow = 4;
        _R = 2*distribution(generator);
        MacierzObr<3> obrot1(50, 'z');
        MacierzObr<3> obrot2(130, 'z');
        MacierzObr<3> obrot3(-50, 'z');
        MacierzObr<3> obrot4(-130, 'z');
        wierzcholki_dol.push_back(obrot1*Wektor<3> {_R, 0, 0});
        wierzcholki_dol.push_back(obrot2*Wektor<3> {_R, 0, 0});
        wierzcholki_dol.push_back(obrot4*Wektor<3> {_R, 0, 0});
        wierzcholki_dol.push_back(obrot3*Wektor<3> {_R, 0, 0});
        for(int i=0; i<l_wierzcholkow; i++){ 
            wierzcholki_gora.push_back(wierzcholki_dol[i]+Wektor<3> {0, 0, wysokosc});
    }
} 

void PlaskowyzProst::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> gorne, dolne;
    vector<vector<drawNS::Point3D>> wierzcholki;
    UkladW uklad(srodek, orientacja, wsk_na_poprz);
    uklad.konwertuj_do_poprz();
    for(int i=0; i<l_wierzcholkow; i++){
        gorne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_gora[i])));
        dolne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_dol[i])));
    }
    wierzcholki.push_back(gorne);
    wierzcholki.push_back(dolne);
    id_rysunku=rysownik->draw_polyhedron(wierzcholki);
}

void PlaskowyzProst::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}
/*
bool PlaskowyzProst::czy_nad(shared_ptr<Dron> dron)
{
    double ODL;
    double odl_min = sin(50)*_R;
    double odl_max = cos(50)*_R;
    if(ODL <= odl_max+dron->get_R() && ODL <= odl_min+dron->get_R()) //{return true;}
    //else return false;
}

bool PlaskowyzProst::czy_ladowac(shared_ptr<Dron> dron)
{
    double ODL;
    double odl_min = sin(50)*_R;
    double odl_max = cos(50)*_R;
    if(ODL <= odl_max && ODL <= odl_min) //{return true;}
    //else return false;
}*/



 

Wzgorze::Wzgorze(double _wysokosc, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
    srodek=_srodek;
    orientacja=_orientacja;
    wsk_na_poprz=rodzic;
    wysokosc =_wysokosc;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution1(6,14);
    uniform_int_distribution<> distribution2(15,20);
    l_wierzcholkow = distribution1(generator);
    double _R;
    max=0;
    min=100;
    for(int i=0; i<l_wierzcholkow; i++){
        MacierzObr<3> obrot(i*(360/l_wierzcholkow), 'z');
        _R = distribution2(generator);
        if(max<_R){max=_R;}
        if(min>_R){min=_R;}
        wierzcholki_dol.push_back(obrot*Wektor<3> {_R, 0, 0});
    }
} 

void Wzgorze::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> gorne, dolne;
    vector<vector<drawNS::Point3D>> wierzcholki;
    UkladW uklad(srodek, orientacja, wsk_na_poprz);
    Wektor<3> wys{0, 0, wysokosc};
    uklad.konwertuj_do_poprz();
    for(int i=0; i<l_wierzcholkow; i++){
        gorne.push_back(konwertuj(uklad.przelicz_punkt(wys)));
        dolne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_dol[i])));
    }
    wierzcholki.push_back(gorne);
    wierzcholki.push_back(dolne);
    id_rysunku=rysownik->draw_polyhedron(wierzcholki);
}

void Wzgorze::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}

bool Wzgorze::czy_nad(shared_ptr<Dron> dron)
{
    Wektor<3> sr_drona=dron->get_srodek();
    if(sqrt(pow(srodek[0]-sr_drona[0], 2)+pow(srodek[1]-sr_drona[1], 2)) <= dron->get_R()+max) {return true;}
    else return false;
}

bool Wzgorze::czy_ladowac(shared_ptr<Dron> dron)
{
    if(czy_nad(dron) == true) {return false;}
    else return true;
}