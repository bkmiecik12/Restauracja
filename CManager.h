//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CMANAGER_H
#define RESTAURACJA_CMANAGER_H


#include "CPracownik.h"

class CManager: CPracownik {
public:
    void podsumuj();

    CManager();
    CManager(double dniowka);
    ~CManager();
};


#endif //RESTAURACJA_CMANAGER_H
