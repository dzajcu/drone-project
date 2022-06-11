#include "Graniastoslup.hh"

Graniastoslup::Graniastoslup(double _wysokosc, double _R, Wektor<3> _srodek, MacierzObr<3> _orientacja, UkladW *rodzic)
{
    srodek=_srodek;
    orientacja=_orientacja;
    wsk_na_poprz=rodzic;
    Wektor<3> wys = {0, 0, _wysokosc};
    MacierzObr<3> obrot(60, 'z');
    wierzcholki_dol[0]={_R, 0, 0};
    wierzcholki_gora[0]=wierzcholki_dol[0]+wys;
    for(int i=1; i<6; i++){
        wierzcholki_dol[i]=obrot*wierzcholki_dol[i-1];
        wierzcholki_gora[i]=wierzcholki_dol[i] + wys;
    }

}

void Graniastoslup::rysuj(drawNS::Draw3DAPI *rysownik)
{
    vector<drawNS::Point3D> gorne, dolne;
    vector<vector<drawNS::Point3D>> wierzcholki;
    UkladW uklad(srodek, orientacja, wsk_na_poprz);
    uklad.konwertuj_do_poprz();
    for(int i=0; i<6; i++){
        gorne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_gora[i])));
        dolne.push_back(konwertuj(uklad.przelicz_punkt(wierzcholki_dol[i])));
    }
    wierzcholki.push_back(gorne);
    wierzcholki.push_back(dolne);
    id_rysunku=rysownik->draw_polyhedron(wierzcholki);
}

void Graniastoslup::zmazuj(drawNS::Draw3DAPI *rysownik)
{
    rysownik->erase_shape(get_id());
}