#ifndef CEG_H_INCLUDED
#define CEG_H_INCLUDED


#include <iostream>
#include <string>

#include "Bejegyzes.h"


class Ceg:public Bejegyzes{
private:
    string nev;
    string telszam;
public:
    Ceg(){}
    Ceg(string nev, string telszam, int azonosito, Cim cim):Bejegyzes(azonosito, cim), nev(nev), telszam(telszam){}
    void setnev(string n) {nev=n;}
    void settelszam(string t) {telszam=t;}
    string getnev(){return nev;}
    string gettelszam(){return telszam;}
    virtual ~Ceg(){};
};
#endif // CEG_H_INCLUDED
