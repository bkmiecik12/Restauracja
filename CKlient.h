//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CKLIENT_H
#define RESTAURACJA_CKLIENT_H

#include <iostream>
#include "CKelner.h"
#include "CDanie.h"

using namespace std;

class CKlient {
private:
    double pieniadze;
    string imie;

public:
    CKelner *kelner;
    CKlient();
    CKlient(double pieniadze, string imie);
    ~CKlient();
    double zamow(CDanie danie);
    void dajNapiwek(CDanie danie);
    string dajImie();

    double rachunek;
};


#endif //RESTAURACJA_CKLIENT_H
