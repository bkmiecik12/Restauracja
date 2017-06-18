//
// Created by bkmiecik on 15.06.17.
//

#include <unistd.h>
#include <fstream>
#include "CRestauracja.h"

void CRestauracja::otworzRestauracje() {
    while(!sprawdzGodzine()){
        losujKlienta();
    }
    zamknijRestauracje();
}

void CRestauracja::zamknijRestauracje() {
    cout << "WYBILA GODZINA ZAMKNIECIA" << endl;
    cout << "MANAGER TERAZ PODSUMUJE CALY DZIEN I WYPISZE TO DO PLIKU" << endl;
    podsumuj();
}

void CRestauracja::losujKlienta() {
    printf("GODZINA: %2d:%02d\n",12+godzina/12,5*(godzina%12));
    int zarodek2 = rand() % 15;
    int zarodek1 = rand() % 100;
    if (zarodek1 >= 30) {
        CKlient* nowy = new CKlient(zarodek1, imiona[zarodek2]);
        nowy->kelner = przypiszKelnera();
        dodajKlienta(nowy);

        cout << "DO RESTAURACJI WSZEDŁ KLIENT O IMIENIU " << nowy->dajImie() << endl;
        sleep(1);

        //losowanie dania
        int los = rand()%4;
        for(int i=0;i<los;i++){
            int nrdania = rand()%5;
            CDanie danie = menu[nrdania];
            kasaFiskalna += nowy->zamow(danie);
            godzina+=kucharz.gotuj();
            //sleep(1);
            godzina+=1;
        }
        //czy wychodzi?
        //jeśli nie to musimy sprawdzić czy kogoś trzeba wyjebać
    }
    else godzina += 1;
}
int CRestauracja::dodajKlienta(CKlient* klient) {
    bool flaga=false;
    int wynik=0;
    for (int i = 0; i < 15; i++)
    {
        if (klienci[i] == NULL && !flaga)
        {
            klienci[i] = klient;
            wynik=i;
            flaga = true;
        }
    }
    return wynik;
}


void CRestauracja::klientWychodzi(CKlient* klient) {
    klient->kelner->dodajReke();
    bool flaga = false;
    for (int i = 0; i < LICZBA_STOLIKOW ; i++)
    {
        if ((klienci[i] == klient) && !flaga)
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

void CRestauracja::podsumuj()
{
    string nazwa;
    ofstream plik;
    double zarobek;
    zarobek = kasaFiskalna;

    cout << "TERAZ MANAGER PODSUMUJE FUNDUSZE RESTAURACJI" << endl;
    cout << "PODAJ NAZWE PLIKU DO KTÓREGO CHCESZ ZAPISAĆ PODSUMOWANIE DNIA" << endl;
    cout << "PAMIETAJ O ROZSZERZENIU .TXT" << endl;
    cin >> nazwa;

    plik.open(nazwa);
    plik << "PODSUMOWANIE DNIA PO 12H PRACY" << endl;
    plik << endl;
    plik << "STAN KASY FISKALNEJ: " << kasaFiskalna << endl;
    plik << endl;
    plik << "KUCHARZ ZAROBIŁ: " << kucharz.dajDniowka() << endl;
    zarobek = zarobek - kucharz.dajDniowka();
    plik << "KELNERZY 1-3 ZAROBILI KOLEJNO ";
    for (int i = 0; i < 3; i++)
    {
        plik << kelner[i]->dajDniowka(); plik<< ", ";
        zarobek = zarobek - kelner[i]->dajDniowka();
    }
    plik << endl << "KELNERZY 1-3 KOLEJNO DOSTALI NAPIWKI WIELKOSCI: ";
    for (int i = 0; i < 3; i++)
    {
        plik << kelner[i]->dajKieszen(); plik << ", ";
    }
    plik << endl << "KELNERZY 1-3 ZAROBILI W SUMIE: ";
    for (int i = 0; i < 3; i++)
    {
        double suma = 0;
        suma = (kelner[i]->dajDniowka()) + kelner[i]->dajKieszen();
        plik << suma;
        plik << ", ";
    }

    plik << endl << "CALKOWITY PRZYCHOD DLA WLASCICIELA TO: " << zarobek << " BRUTTO" << endl;
    plik << "PO OPODATKOWANIU: " << zarobek*0.8 << " NETTO" << endl;

}

CRestauracja::CRestauracja() {
    manager = CManager(200.0);
    kucharz = CKucharz(120.0);

    menu[0] = CDanie("rosol", 5, 0, 1);
    menu[1] = CDanie("warzywna", 5, 1, 1);
    menu[2] = CDanie("kurczak", 10, 0, 0);
    menu[3] = CDanie("lody", 8, 2, 3);
    menu[4] = CDanie("shake", 6, 3, 3);


    for (int i = 0; i < 3; i++)
    {
        kelner[i] = new CKelner(60.0);
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

CKelner * CRestauracja::przypiszKelnera() {
    for(int i=0;i<3;i++)
        if(kelner[i]->ileRak()>0) return kelner[i];
}

void CRestauracja::wywalKlienta() {
    int los;
    los = rand() % LICZBA_STOLIKOW;
    klientWychodzi(klienci[los]);
}

