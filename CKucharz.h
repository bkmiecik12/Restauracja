//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CKUCHARZ_H
#define RESTAURACJA_CKUCHARZ_H


#include "CPracownik.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;

class CKucharz: public CPracownik {
public:
    int lodowka[10];


public:

    CKucharz();
    CKucharz(double dniowka);
    ~CKucharz();

    int gotuj();
    void otworzLodowke();

};


#endif //RESTAURACJA_CKUCHARZ_H
