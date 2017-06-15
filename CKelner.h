//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CKELNER_H
#define RESTAURACJA_CKELNER_H


#include "CPracownik.h"

class CKelner: public CPracownik {
private :
    static int rece;
    double kieszen;

public:

    void wezNapiwek(double);
    void dodajReke();

    CKelner();
    CKelner(double);
    ~CKelner();

};


#endif //RESTAURACJA_CKELNER_H
