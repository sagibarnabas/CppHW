#ifndef BEJEGYZES_H_INCLUDED
#define BEJEGYZES_H_INCLUDED


#include "Telszam.h"
#include "Cim.h"
#include "Nev.h"

class Bejegyzes{
private:
    int azonosito;
    Cim cim;
public:
    Bejegyzes(){};
    Bejegyzes(int azonosito, Cim cim):azonosito(azonosito), cim(cim){};

    Cim getcim(){return cim;}
    void setcim(Cim c) {cim=c;}
    int getazonosito(){return azonosito;}
    void setazonosito(int a){azonosito=a;}

    virtual void setembernev(Embernev n){}
    virtual void setembertelszam(Embertelszam t){}
    virtual Embernev getembernev(){return Embernev("null", "null", "null");}
    virtual Embertelszam getembertelszam(){return Embertelszam("null", "null");}

    virtual void setnev(string n){}
    virtual void settelszam(string t){}
    virtual string getnev(){return "null";}
    virtual string gettelszam(){return "null";}

    virtual ~Bejegyzes(){};
};


#endif // BEJEGYZES_H_INCLUDED
