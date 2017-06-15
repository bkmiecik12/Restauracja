//
// Created by bkmiecik on 15.06.17.
//

#ifndef RESTAURACJA_CPRACOWNIK_H
#define RESTAURACJA_CPRACOWNIK_H


class CPracownik {
private:
    double dniowka;

public:

    double dajDniowka();
    void setDniowka(double);

    CPracownik();
    CPracownik(double);
    ~CPracownik();
};


#endif //RESTAURACJA_CPRACOWNIK_H
