//
// Created by bkmiecik on 15.06.17.
//

#include <unistd.h>
#include "CKlient.h"

CKlient::CKlient() {

}

CKlient::CKlient(double pieniadze, string imie) {
    this->pieniadze = pieniadze;
    this->imie = imie;
    rachunek = 0;
}

CKlient::~CKlient() {

}

double CKlient::zamow(CDanie danie) {
    cout << "KLIENT " << imie << " ZAMOWIL DANIE " << danie.dajNazwe() << endl;
    sleep(1);
    rachunek+=danie.dajCene();
    int zarodek = rand() % 6;
    if (zarodek < 2)
    {
        dajNapiwek(danie);
        cout << "KLIENT " << this->imie << " DAL NAPIWEK "<< endl;
        sleep(1);
    }
    return danie.dajCene();
}

void CKlient::dajNapiwek(CDanie danie) {
    kelner->wezNapiwek(danie.dajCene()*0.1);
}

string CKlient::dajImie() {
    return imie;
}
