#ifndef EMBER_H_INCLUDED
#define EMBER_H_INCLUDED

#include "Bejegyzes.h"


class Ember:public Bejegyzes{
private:
    Embernev enev;
    Embertelszam etelszam;
public:
    Ember(){}
    Ember(Embernev enev, Embertelszam etelszam, int azonosito, Cim cim):Bejegyzes(azonosito, cim), enev(enev), etelszam(etelszam){}
    void setembernev(Embernev n) {}
    void setembertelszam(Embertelszam t){}
    Embernev getembernev(){return enev;}
    Embertelszam getembertelszam(){return etelszam;}
    virtual ~Ember(){};
};


#endif // EMBER_H_INCLUDED
