#ifndef DINTOMB_H_INCLUDED
#define DINTOMB_H_INCLUDED

#include "ceg.h"
#include "Ember.h"
#include "Cim.h"
#include "Bejegyzes.h"
#include <vector>
#include <cstddef>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class Dintomb{
private:
    vector<Bejegyzes*> dolgok;
public:
    Dintomb(){}
    Dintomb(Bejegyzes *dolog){dolgok.push_back(dolog);};
    void hozzaadceg(string neve,string telefonszama, int azonja, int irszama,string varosa , string utcaja,int hazszama);
    void hozzaadember(string keresztneve,string vezetekneve,string beceneve,string privatja, string munkahelyije, int azonja, int irszama, string varosa, string utcaja, int hazszama);
    void torol(int);
    vector<Bejegyzes*> getvektor() {return dolgok;}
    void fajlbe();
    void fajlki();
    void keresnev(string n);
    void kerestelszam(string t);
    void keresazon(int a);
    void listazazon();
    void listaznev();
    ~Dintomb(){
        for(size_t i=0; i< dolgok.size(); i++)
            delete dolgok[i];}
};

#endif // DINTOMB_H_INCLUDED
