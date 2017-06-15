//
// Created by bkmiecik on 15.06.17.
//

#include "CDanie.h"

int CDanie::dajSkladniki() {
    return skladniki[0]*10+skladniki[1];
}

double CDanie::dajCene() {
    return cena;
}

string CDanie::dajNazwe() {
    return nazwa;
}

CDanie::CDanie() {

}

CDanie::CDanie(string n, double c, int s1, int s2) {
    nazwa = n;
    cena = c;
    skladniki[0] = s1;
    skladniki[1] = s2;
}

CDanie::~CDanie() {

}
