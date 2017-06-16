//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CKELNER_H
#define RESTAURACJA_CKELNER_H


#include "CPracownik.h"
#include <iostream>

using namespace std;

class CKelner: public CPracownik {
private :
    int rece; //not static
    double kieszen;

public:

    void wezNapiwek(double);
    void dodajReke();
    int ileRak();

    CKelner();
    CKelner(double);
    ~CKelner();

    double dajKieszen();
};


#endif //RESTAURACJA_CKELNER_H
