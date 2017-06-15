//
// Created by bkmiecik on 15.06.17.
//

#include <unistd.h>
#include "CRestauracja.h"

void CRestauracja::otworzRestauracje() {
    while(!sprawdzGodzine()){
        losujKlienta();
    }
}

void CRestauracja::zamknijRestauracje() {
    if (sprawdzGodzine())
    {
        cout << "WYBILA GODZINA ZAMKNIECIA" << endl;
        cout << "MANAGER TERAZ PODSUMUJE CALY DZIEN I WYPISZE TO DO PLIKU" << endl;
    }
}

bool CRestauracja::losujKlienta() {
    int zarodek2 = rand() % 15;
    int zarodek1 = rand() % 100;
    if (zarodek1 >= 30){
        CKlient* nowy = new CKlient(zarodek1, imiona[zarodek2]);
        dodajKlienta(nowy);
        //obsługa kelnera
        cout << "DO RESTAURACJI WSZEDŁ KLIENT O IMIENIU" << nowy->dajImie() << endl;
        sleep(800);
        return true;
    }
    return false;
}

void CRestauracja::dodajKlienta(CKlient *klient) {
    bool flaga=false;
    for (int i = 0; i < 15; i++)
    {
        if (klienci[i] != NULL && !flaga)
        {
            klienci[i] = klient;
            flaga = true;
        }
    }
}

void CRestauracja::klientWychodzi(CKlient *klient) {
    klient->kelner->dodajReke();
    bool flaga = false;
    for (int i = 0; i < 15; i++)
    {
        if (klienci[i] == klient && !flaga)
        {
            klienci[i] = NULL;
            flaga = true;
        }
    }
}

bool CRestauracja::sprawdzGodzine() {
    if(godzina<144)	return false;
    return true;
}

CRestauracja::CRestauracja() {
    manager = CManager(200.0);
    kucharz = CKucharz(120.0);

    for (int i = 0; i < 3; i++)
    {
        kelner[i] = CKelner(60.0);
    }

    for (int i = 0; i < 15; i++)
    {
        klienci[i] = NULL;
    }


    godzina = 0;
    kasaFiskalna = 200.0;
}

CRestauracja::~CRestauracja() {

}
