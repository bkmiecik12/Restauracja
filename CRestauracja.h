//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CRESTAURACJA_H
#define RESTAURACJA_CRESTAURACJA_H


#include "CDanie.h"
#include "CManager.h"
#include "CKucharz.h"
#include "CKelner.h"
#include "CKlient.h"


class CRestauracja {
private:

    double kasaFiskalna;
    int godzina;
    CDanie menu[5];
    CManager manager;
    CKucharz kucharz;
    CKelner* kelner[3];
    CKlient* klienci[15];
    //[15]
    string imiona[15] = {"Wiesiek", "Marek", "Stefan", "Janusz", "Pawulon", "Karol", "Krystyna", "Grazyna", "Bogumila", "Bozena", "Boguniemila", "Boguobojetna", "Jozefina", "Ewelina", "Janina"};

    const int LICZBA_STOLIKOW =15;

public:

    void otworzRestauracje();
    void zamknijRestauracje();

    //MENU:


    void losujKlienta(); //Sprawdz i przypisz kelnera
    CKelner * przypiszKelnera();
    void wywalKlienta();


    int dodajKlienta(CKlient *klient);
    void klientWychodzi(CKlient *klient);

    bool sprawdzGodzine();

    CRestauracja();
    ~CRestauracja();

    void podsumuj();
};


#endif //RESTAURACJA_CRESTAURACJA_H
