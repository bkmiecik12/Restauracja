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
    int zarodek = rand() % 6;
    if (zarodek <= 2)
    {
        dajNapiwek(danie);
    }
    cout << "KLIENT" << this->imie << "ZAMOWIL DANIE" << danie.dajNazwe() << endl;
    sleep(800);
    return danie.dajCene();
}

double CKlient::dajNapiwek(CDanie danie) {
    return 0.1 * danie.dajCene();
}

string CKlient::dajImie() {
    return imie;
}
