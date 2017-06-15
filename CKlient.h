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
    double rachunek;

public:
    CKelner *kelner;
    CKlient();
    CKlient(double pieniadze, string imie);
    ~CKlient();
    double zamow(CDanie danie);
    double dajNapiwek(CDanie danie);
    string dajImie();
};


#endif //RESTAURACJA_CKLIENT_H
