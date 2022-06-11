#include "Scena.hh"
#include "Powierzchnia.hh"
#include "Obiekty.hh"
#include "Dron.hh"

Scena::Scena(drawNS::Draw3DAPI *_rysownik)
{
        rysownik=_rysownik;
        shared_ptr<Powierzchnia> powierzchnia = shared_ptr<Powierzchnia>(new Powierzchnia(0.0));
        shared_ptr<Wzgorze> wzgorze = shared_ptr<Wzgorze>(new Wzgorze(20, {-30.0, -30.0, 0.0}, MacierzObr<3>()));
        shared_ptr<Plaskowyz> plaskowyz = shared_ptr<Plaskowyz>(new Plaskowyz(10, {20.0, -20.0, 0.0}, MacierzObr<3>()));
        shared_ptr<PlaskowyzProst> plaskowyz_prost = shared_ptr<PlaskowyzProst>(new PlaskowyzProst(15, {50.0, 40.0, 0.0}, MacierzObr<3>()));
        dron = shared_ptr<Dron>(new Dron({-10.0, 12.0, 0.0}, MacierzObr<3>(0.0, 'z')));
        rysuj.push_back(dron);
        rysuj.push_back(powierzchnia);
        rysuj.push_back(plaskowyz);
        rysuj.push_back(plaskowyz_prost);
        rysuj.push_back(wzgorze);
        el_krajobrazu.push_back(plaskowyz);
        el_krajobrazu.push_back(plaskowyz_prost);
        el_krajobrazu.push_back(wzgorze);
}

void Scena::animacja(double wysokosc, double kat, double odleglosc, drawNS::Draw3DAPI *rysownik) 
{   int wyladowal=0;
    double wys=0;
    int l_klatek = 40;
     for(int i=0; i<l_klatek; i++){
         dron->zmazuj(rysownik);
         dron->wznies(wysokosc/(double)l_klatek);
         dron->porusz_wirnikami();
         dron->rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(100));
     } 
     for(int i=0; i<l_klatek; i++){
         dron->zmazuj(rysownik);
         dron->obroc(kat/(double)l_klatek);
         dron->porusz_wirnikami();
         dron->rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(100));
     } 
     for(int i=0; i<l_klatek; i++){
         dron->zmazuj(rysownik);
         dron->lec(odleglosc/(double)l_klatek);
         dron->porusz_wirnikami();
         dron->rysuj(rysownik);
         rysownik->redraw();
         this_thread::sleep_for(chrono::microseconds(100));
     }


for (shared_ptr<InterKrajobrazu> & x : el_krajobrazu)
{
    if(x->czy_nad(dron)==true)
    {
        cout << "Dron nad obiektem" << endl;
 
        if(x->czy_ladowac(dron)==true)
        {
            cout << "Ladujemy" <<  x->get_wysokosc() << endl;
            wys=-wysokosc+x->get_wysokosc();
            for(int i=0; i<l_klatek; i++)
            {
                dron->zmazuj(rysownik);
                dron->wznies(wys/(double)l_klatek);
                dron->porusz_wirnikami();
                dron->rysuj(rysownik);
                rysownik->redraw();
                this_thread::sleep_for(chrono::microseconds(100));
            }
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
 
        if(x->czy_ladowac(dron)==false)
        {
            cout << "Brak mozliwosci ladowania, o ile przesunac drona:" << endl;
            cin >> odleglosc;
            for(int i=0; i<l_klatek; i++)
            {
                dron->zmazuj(rysownik);
                dron->lec(odleglosc/(double)l_klatek);
                dron->porusz_wirnikami();
                dron->rysuj(rysownik);
                rysownik->redraw();
                this_thread::sleep_for(chrono::microseconds(100));
            }
                    
            if(x->czy_nad(dron)==false)
            {
                cout << "Ladujemy gdzies dalej" << endl;
                for(int i=0; i<l_klatek; i++)
                {
                    dron->zmazuj(rysownik);
                    dron->wznies(-wysokosc/(double)l_klatek);
                    dron->porusz_wirnikami();
                    dron->rysuj(rysownik);
                    rysownik->redraw();
                    this_thread::sleep_for(chrono::microseconds(100));
                }
            }
            /*
            if(x->czy_ladowac(dron)==true)
            {
                cout << "Ladujemy2" << endl;
                for(int i=0; i<l_klatek; i++)
                {
                    dron->zmazuj(rysownik);
                    dron->wznies((-wysokosc+x->get_wysokosc())/(double)l_klatek);
                    dron->porusz_wirnikami();
                    dron->rysuj(rysownik);
                    rysownik->redraw();
                    this_thread::sleep_for(chrono::microseconds(100));
                }
            }*/
        }
    wyladowal = 1;           
    }
 
}
if (wyladowal != 1)
{
    for(int i=0; i<l_klatek; i++)
    {
        dron->zmazuj(rysownik);
        dron->wznies(-wysokosc/(double)l_klatek);
        dron->porusz_wirnikami();
        dron->rysuj(rysownik);
        rysownik->redraw();
        this_thread::sleep_for(chrono::microseconds(100));
    }
}
    
}

void Scena::dodaj_obiekt()
{
    int wybor;
    double wysokosc, x, y;
    cout << "Jaki typ obiektu chcesz dodac:" << endl << "1: wzgorze" << endl << "2: plaskowyz" << endl << "3: plaskowyz prostopadloscienny" << endl;
    cout << "Twoj wybor:" << endl;
    cin >> wybor;
    switch(wybor)
    {
        case 1:
            cout << "Podaj wysokosc wzgorza:" << endl;
            cin >> wysokosc;
            cout << "Podaj wspolrzedna 'x' srodka wzgorza:" << endl;
            cin >> x;
            cout << "Podaj wspolrzedna 'y' srodka wzgorza:" << endl;
            cin >> y;
        break;

        case 2:
            cout << "Podaj wysokosc plaskowyzu:" << endl;
            cin >> wysokosc;
            cout << "Podaj wspolrzedna 'x' srodka plaskowyzu:" << endl;
            cin >> x;
            cout << "Podaj wspolrzedna 'y' srodka plaskowyzu:" << endl;
            cin >> y;
        break;

        case 3:
            cout << "Podaj wysokosc plaskowyzu prostopadlosciennego:" << endl;
            cin >> wysokosc;
            cout << "Podaj wspolrzedna 'x' srodka plaskowyzu prostopadlosciennego:" << endl;
            cin >> x;
            cout << "Podaj wspolrzedna 'y' srodka plaskowyzu prostopadlosciennego:" << endl;
            cin >> y;
        break;

        default:
            cerr << "Podano bledna opcje" << endl;
        break;
    }

            if(wybor==1){
                shared_ptr<Wzgorze> wzgorze = shared_ptr<Wzgorze>(new Wzgorze(wysokosc, {x, y, 0.0}, MacierzObr<3>()));
                rysuj.push_back(wzgorze);
                el_krajobrazu.push_back(wzgorze);
            }
            if(wybor==2){
                shared_ptr<Plaskowyz> plaskowyz = shared_ptr<Plaskowyz>(new Plaskowyz(wysokosc, {x, y, 0.0}, MacierzObr<3>()));
                rysuj.push_back(plaskowyz);
                el_krajobrazu.push_back(plaskowyz);
            }
            if(wybor==3){
                shared_ptr<PlaskowyzProst> plaskowyz_prost = shared_ptr<PlaskowyzProst>(new PlaskowyzProst(wysokosc, {x, y, 0.0}, MacierzObr<3>()));
                rysuj.push_back(plaskowyz_prost);
                el_krajobrazu.push_back(plaskowyz_prost);
            }
}

void Scena::usun_obiekt()
{
    el_krajobrazu.pop_back();
    rysuj.pop_back();
}

void Scena::rysuj_wszystkie()
{
    for (shared_ptr<InterRysowania> & x : rysuj){
     	x->rysuj(rysownik);
    }
}

void Scena::zmazuj_wszystkie()
{
    for (shared_ptr<InterRysowania> & x : rysuj){
     	x->zmazuj(rysownik);
    }
}