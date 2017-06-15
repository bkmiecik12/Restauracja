//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CDANIE_H
#define RESTAURACJA_CDANIE_H

#include <iostream>
using namespace std;


class CDanie {
private:
    int skladniki[2];
    double cena;
    string nazwa;

public:

    int dajSkladniki();
    double dajCene();
    string dajNazwe();


    CDanie();
    CDanie(string, double, int, int);
    ~CDanie();
};


#endif //RESTAURACJA_CDANIE_H
