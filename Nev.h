#ifndef NEV_H_INCLUDED
#define NEV_H_INCLUDED

using namespace std;

class Embernev
{
    string vezetek;
    string bece;
    string kereszt;
public:
    Embernev(){};
    Embernev(string vezetek, string bece, string kereszt):vezetek(vezetek), bece(bece), kereszt(kereszt) {};
    void setkereszt(string k) {};
    void setvezetek(string v) {};
    void setbece(string b) {};
    string getkereszt() {return kereszt;};
    string getvezetek() {return vezetek;};
    string getbece() {return bece;};
    ~Embernev(){};
};


#endif // NEV_H_INCLUDED
