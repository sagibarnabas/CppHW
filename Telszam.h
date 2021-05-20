#ifndef TELSZAM_H_INCLUDED
#define TELSZAM_H_INCLUDED

using namespace std;

class Embertelszam
{
    string privat;
    string munkahelyi;
public:
    Embertelszam(){};
    Embertelszam(string privat, string munkahelyi): privat(privat), munkahelyi(munkahelyi) {};
    void setprivat(string p) {};
    void setmunkahelyi(string m) {};
    string getprivat() const{return privat;};
    string getmunkahelyi() const{return munkahelyi;};
    ~Embertelszam(){};
};

#endif // TELSZAM_H_INCLUDED
