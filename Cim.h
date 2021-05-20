#ifndef CIM_H_INCLUDED
#define CIM_H_INCLUDED


using namespace std;

class Cim{
    int irszam;
    string varos;
    string utca;
    int hazszam;
public:
    Cim(){};
    Cim(int irszam, string varos, string utca, int hazszam): irszam(irszam), varos(varos), utca(utca), hazszam(hazszam) {};
    void setirszam(int ir) {};
    void setvaros(string v) {};
    void setutca(string u) {};
    void sethazszam(int h) {};
    int getirszam() const{return irszam;};
    string getvaros() const{return varos;};
    string getutca() const{return utca;};
    int gethazszam() const{return hazszam;};
    ~Cim(){};
};

#endif // CIM_H_INCLUDED
