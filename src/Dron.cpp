#include "Dron.hh"
#include <thread>
#include <chrono>

Dron::Dron(Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
        srodek=_srodek;
        orientacja=_orientacja;
        wsk_na_poprz=rodzic;
        korpus=Prostopadloscian(Wektor<3> {-5, 0, 0}, Wektor<3> {-5, 0, 3}, Wektor<3> {-5, 8, 3}, Wektor<3> {-5, 8, 0},
                                Wektor<3> {4, 0, 0},  Wektor<3> {4, 0, 3},  Wektor<3> {4, 8, 3},  Wektor<3> {4, 8, 0}, 
                                Wektor<3> {0, 0, 0}, MacierzObr<3>(), this); 
               
        wirniki[0]=Graniastoslup(0.5, 3.0, Wektor<3> {-5, 0, 3}, MacierzObr<3>(), this);
        wirniki[1]=Graniastoslup(0.5, 3.0, Wektor<3> {-5, 8, 3}, MacierzObr<3>(), this);
        wirniki[2]=Graniastoslup(0.5, 3.0, Wektor<3> {4, 0, 3}, MacierzObr<3>(), this); 
        wirniki[3]=Graniastoslup(0.5, 3.0, Wektor<3> {4, 8, 3}, MacierzObr<3>(), this);
        R=sqrt(pow(9, 2)+pow(8, 2))/2;
}

void Dron::rysuj(drawNS::Draw3DAPI *rysownik)
{ 
    korpus.rysuj(rysownik);
    for(int i=0; i<4; i++){
    wirniki[i].rysuj(rysownik);
    }
}

void Dron::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(korpus.get_id());
    for(int i=0; i<4; i++){
    rysownik->erase_shape(wirniki[i].get_id());
    }
}

void Dron::wznies(double wysokosc)
{
    Wektor<3> wznies{0, 0, wysokosc};
    this->Translacja(orientacja*wznies);
}

void Dron::lec(double odleglosc)
{   
    Wektor<3> lec{odleglosc, 0, 0};
    this->Translacja(orientacja*lec);
}

void Dron::obroc(double kat)
{
    MacierzObr<3> obrot(kat, 'z'); 
    this->Obrot(obrot);
}

void Dron::porusz_wirnikami()
{
    MacierzObr<3> prawo(10, 'z');
    MacierzObr<3> lewo(-10, 'z');
    wirniki[0].Obrot(prawo);
    wirniki[1].Obrot(lewo);
    wirniki[2].Obrot(lewo);
    wirniki[3].Obrot(prawo);
}
/*
void Dron::animacja(double wysokosc, double kat, double odleglosc, drawNS::Draw3DAPI *rysownik) 
{ 
    int l_klatek = 40;
     for(int i=0; i<l_klatek; i++){
         zmazuj(rysownik);
         wznies(wysokosc/(double)l_klatek);
         porusz_wirnikami();
         rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(40));
     } 
     for(int i=0; i<l_klatek; i++){
         zmazuj(rysownik);
         obroc(kat/(double)l_klatek);
         porusz_wirnikami();
         rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(40));
     } 
     for(int i=0; i<l_klatek; i++){
         zmazuj(rysownik);
         lec(odleglosc/(double)l_klatek);
         porusz_wirnikami();
         rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(40));
     }
     for(int i=0; i<l_klatek; i++){
         zmazuj(rysownik);
         wznies(-wysokosc/(double)l_klatek);
         porusz_wirnikami();
         rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(40));
     } 

}*/