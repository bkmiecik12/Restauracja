//
// Created by bkmiecik on 15.06.17.
//


#include <unistd.h>
#include "CKucharz.h"
using namespace std;

CKucharz::CKucharz() {

}

void CKucharz::otworzLodowke() {
    for (int i = 0; i < 10; i++)
    {
        if (lodowka[i] == 0)
        {
            cout << "W lodowce na " << i << " polce, znajduje sie mieso" << endl;
        }
        if (lodowka[i] == 1)
        {
            cout << "W lodowce na " << i << " polce, znajduje sie warzywa" << endl;
        }
        if (lodowka[i] == 2)
        {
            cout << "W lodowce na " << i << " polce, znajduje sie nabial" << endl;
        }
        if (lodowka[i] == 3)
        {
            cout << "W lodowce na " << i << " polce, znajduje sie owoce" << endl;
        }
    }
}

CKucharz::CKucharz(double dniowka) : CPracownik(dniowka) {

}

CKucharz::~CKucharz() {

}

int CKucharz::gotuj() {
    cout << "Kucharz rozpoczyna gotowanie" << endl;
    sleep(1);
    cout << "Kucharz skonczyl gotowac" << endl;
    return 5;
}
