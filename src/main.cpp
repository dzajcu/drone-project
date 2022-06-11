#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include <cmath>
#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "Scena.hh"
#include "Powierzchnia.hh"
#include "Obiekty.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wyswietl_menu()
{
    cout << " Menu programu: " << endl;
    cout << " l - lec! - rozpoczecie procedury startu drona " << endl;
    cout << " d - dodaj obiekt " << endl;
    cout << " u - usun ostatnio dodany obiekt " << endl;
    cout << " w - wyswietl liczbe wektorow " << endl;
    cout << " m - wyswietlenie menu programu " << endl;
    cout << " k - zakonczenie dzialania programu " << endl;
}



int main()
{
    drawNS::Draw3DAPI *rysownik = new drawNS::APIGnuPlot3D(-50, 50, -50, 50, -50, 50);

    double kat, wysokosc, odleglosc;
    char wybor;
    UkladW glowny({0.0, 0.0, 0.0}, MacierzObr<3> (), nullptr);
    Wektor<3> wektory;
    Scena scena(rysownik);
    scena.rysuj_wszystkie();
    rysownik->redraw();
    wyswietl_menu();


    do{
        cout << " Twoj wybor: " << endl;
        cin >> wybor;

        switch (wybor){

            case 'l':
                cout << "Podaj kat obrotu" << endl;
                cin >> kat;
                cout << "Podaj wysokosc lotu" << endl;
                cin >> wysokosc;
                cout << "Podaj odleglosc" << endl;
                cin >> odleglosc;
                scena.animacja(wysokosc, kat, odleglosc, rysownik);
            break;

            case 'w':
                cout << "Liczba wektorow w tej chwili:" << wektory.get_obecnie() << endl;
                cout << "Liczba wektorow lacznie:" << wektory.get_wszystkie() << endl;

            case 'm':
                    wyswietl_menu();
            break;
            
            case 'd':
                cout << "Dodaj obiekt" << endl;
                scena.dodaj_obiekt();
                this_thread::sleep_for(chrono::milliseconds(10));
                scena.zmazuj_wszystkie();
                scena.rysuj_wszystkie();
                rysownik->redraw();
            break;

            case 'u':
                scena.zmazuj_wszystkie();
                scena.usun_obiekt();
                scena.rysuj_wszystkie();
                rysownik->redraw();
            break;

            case 'k':
             break;


            default:
                    cerr << " Bledna opcja " << endl;
            break;
        }
    }while (wybor != 'k');
}