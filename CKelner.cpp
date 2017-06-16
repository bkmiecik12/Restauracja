//
// Created by bkmiecik on 15.06.17.
//

#include <netinet/in.h>
#include "CKelner.h"

CKelner::~CKelner() {

}//+=
void CKelner::wezNapiwek(double x) {
    kieszen += x;
}

void CKelner::dodajReke() {
    rece++;
}

double CKelner::dajKieszen(){
    return kieszen;
}

CKelner::CKelner() {

}

CKelner::CKelner(double dniowka) : CPracownik(dniowka){
    rece = 2;
    kieszen = 0;
}

int CKelner::ileRak() {
    return rece;
}

