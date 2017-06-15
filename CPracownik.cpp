//
// Created by bkmiecik on 15.06.17.
//

#include "CPracownik.h"

CPracownik::~CPracownik() {

}

CPracownik::CPracownik(double x ) {
    dniowka=x;
}

CPracownik::CPracownik() {

}

void CPracownik::setDniowka(double x) {
    dniowka=x;
}

double CPracownik::dajDniowka() {
    return dniowka;
}
