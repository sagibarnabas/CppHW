#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>


#include "gtest_lite.h"
#include "Dintomb.h"
#include "ceg.h"
#include "Ember.h"

//1-> Tesztesetek, 0-> program futtatas
#define tesztem 0

using namespace std;

int main()
{
    #if tesztem == 0
    Dintomb a;
    a.fajlbe();
    int valaszt;
    while(!(valaszt == 6)){
        int valaszt2=0;
        string valaszstr;
        int valaszint;
        int azonja;
        int irszama;
        string varosa;
        string utcaja;
        int hazszama;
        string keresztneve;
        string vezetekneve;
        string beceneve;
        string privatja;
        string munkahelyije;

        cout << "Valassz a menupontok kozul:\n" << "1. Adatok felvetele.\n" << "2. Adatok torlese.\n" << "3. Adatok modositasa.\n" << "4. Listazas.\n" << "5. Kereses.\n" << "6. Kilepes a programbol.\n";
        cin >> valaszt;
        if(valaszt == 1){
            bool foglalt =true;
            cout << "Ceg(1), vagy szemely(2)?";
            cin >> valaszt2;
            if(valaszt2 == 1){
                cout << "Mi a ceg neve?";
                cin >> keresztneve;
                cout << "Mi a ceg telefonszama?";
                cin >> privatja;
                cout << "Mi a ceg iranyitoszama?(szam)";
                cin >> irszama;
                cout << "Melyik varosban van a ceg?";
                cin >> varosa;
                cout << "Melyik utcaban van a ceg?";
                cin >> utcaja;
                cout << "Mi a ceg hazszama?(szam)";
                cin >> hazszama;
                while(foglalt){
                    cout << "Adjon meg azonositot!(szam)";
                    cin >> azonja;
                    foglalt=false;
                    for(size_t i=0; i<a.getvektor().size();i++)
                        if(a.getvektor()[i]->getazonosito()==azonja)
                            foglalt=true;
                }
                a.hozzaadceg(keresztneve,privatja,azonja,irszama,varosa, utcaja, hazszama);
                a.fajlki();
            }else if(valaszt2 == 2){
                cout << "Mi a vezetekneve?";
                cin >> vezetekneve;
                cout << "Mi a beceneve?";
                cin >> beceneve;
                cout << "Mi a keres?";
                cin >> keresztneve;
                cout << "Mi a munkahelyi telefonszama?";
                cin >> munkahelyije;
                cout << "Mi a privat telefonszama?";
                cin >> privatja;
                cout << "Mi az iranyitoszama?(szam)";
                cin >> irszama;
                cout << "Melyik varosban lakik?";
                cin >> varosa;
                cout << "Melyik utcaban lakik?";
                cin >> utcaja;
                cout << "Mi a hazszama(szam)?";
                cin >> hazszama;
                while(foglalt){
                    cout << "Adjon meg azonositot!(szam)";
                    cin >> azonja;
                    foglalt=false;
                    for(size_t i=0; i<a.getvektor().size();i++)
                        if(a.getvektor()[i]->getazonosito()==azonja)
                            foglalt=true;
                }
                a.hozzaadember(vezetekneve,beceneve,keresztneve, privatja,munkahelyije,azonja,irszama,varosa, utcaja, hazszama);
                a.fajlki();
            }
        }
        if(valaszt == 2){
            cout << "Melyiket toroljem?(azonosito)";
            cin >> valaszint;
            bool vanilyen = false;
            int i;
            for(i=0; i<int(a.getvektor().size()); i++){
                if(a.getvektor()[i]->getazonosito() == valaszint){
                    vanilyen = true;
                    break;
                }
            }
            if (vanilyen){
                a.torol(i);
            }else{
                cout << "Nincs ilyen azonosito.\n";
            }
            a.fajlki();
        }
        if(valaszt == 3){
            bool foglalt =true;
            cout << "Melyiket moditsam?(azonosito)";
            cin >> valaszint;
            bool vanilyen = false;
            int i;
            for(i=0; i<int(a.getvektor().size()); i++){
                if(a.getvektor()[i]->getazonosito() == valaszint){
                    vanilyen = true;
                    break;
                }
            }
            if (vanilyen){
                cout << "Ceg(1), vagy szemely(2) legyen?";
                cin >> valaszt2;
                if(valaszt2 == 1){
                    cout << "Mi a ceg neve?";
                    cin >> keresztneve;
                    cout << "Mi a ceg telefonszama?";
                    cin >> privatja;
                    cout << "Mi a ceg iranyitoszama?(szam)";
                    cin >> irszama;
                    cout << "Melyik varosban van a ceg?";
                    cin >> varosa;
                    cout << "Melyik utcaban van a ceg?";
                    cin >> utcaja;
                    cout << "Mi a ceg hazszama?(szam)";
                    cin >> hazszama;
                    while(foglalt){
                        cout << "Adjon meg azonositot!(szam)";
                        cin >> azonja;
                        foglalt=false;
                        for(size_t i=0; i<a.getvektor().size();i++)
                            if(a.getvektor()[i]->getazonosito()==azonja)
                                foglalt=true;
                    }
                    a.torol(i);
                    a.hozzaadceg(keresztneve,privatja,azonja,irszama,varosa, utcaja, hazszama);
                    a.fajlki();
                }else if(valaszt2 == 2){
                    cout << "Mi a vezetekneve?";
                    cin >> vezetekneve;
                    cout << "Mi a beceneve?";
                    cin >> beceneve;
                    cout << "Mi a keresztneve?";
                    cin >> keresztneve;
                    cout << "Mi a munkahelyi telefonszama?";
                    cin >> munkahelyije;
                    cout << "Mi a privat telefonszama?";
                    cin >> privatja;
                    cout << "Mi az iranyitoszama?(szam)";
                    cin >> irszama;
                    cout << "Melyik varosban lakik?";
                    cin >> varosa;
                    cout << "Melyik utcaban lakik?";
                    cin >> utcaja;
                    cout << "Mi a hazszama?(szam)";
                    cin >> hazszama;
                    while(foglalt){
                        cout << "Adjon meg azonositot!(szam)";
                        cin >> azonja;
                        foglalt=false;
                        for(size_t i=0; i<a.getvektor().size();i++)
                            if(a.getvektor()[i]->getazonosito()==azonja)
                                foglalt=true;
                    }
                    a.torol(i);
                    a.hozzaadember(vezetekneve,beceneve,keresztneve, privatja,munkahelyije,azonja,irszama,varosa, utcaja, hazszama);
                    a.fajlki();
                }
            }else{
                cout << "Nincs ilyen azonosito.\n";
            }
        }
        if(valaszt == 4){
            valaszt=0;
            while(valaszt!=4){
                cout << "Valassz a menupontok kozul:\n" << "1. Nev szerinti rendezes.\n" << "2. Azonosito szerinti rendezes.\n" << "3. Kilepes a fomenube.\n" << "4. Kilepes a programbol.\n";
                cin >> valaszt;
                if(valaszt == 1){
                    a.listaznev();
                }else if(valaszt == 2){
                    a.listazazon();
                }else if(valaszt == 3){
                    break;
                }
            }
            if(valaszt == 4){
                valaszt=6;
            }
        }
        if(valaszt == 5){
            valaszt=0;
            while(valaszt!=5){
                cout << "Valassz a menupontok kozul:\n" << "1. Nev szerinti kereses.\n" << "2. Azonosito szerinti kereses.\n" << "3. Telefonszam szerinti kereses.\n" << "4. Kilepes a fomenube.\n" << "5. Kilepes a programbol.\n";
                cin >> valaszt;
                if(valaszt == 1){
                    cout << "Kit keresel(nev)?";
                    cin >> valaszstr;
                    a.keresnev(valaszstr);
                }else if(valaszt == 2){
                    cout << "Kit keresel(azonosito)?";
                    cin >> valaszint;
                    a.keresazon(valaszint);
                }else if(valaszt == 3){
                    cout << "Kit keresel(telefonszam)?";
                    cin >> valaszstr;
                    a.kerestelszam(valaszstr);
                }else if(valaszt == 4){
                    break;
                }
            }
            if(valaszt == 5){
                valaszt=6;
            }
        }
        if(cin.eof()){
            valaszt=6;
        }
    }
#endif // tesztem

#if tesztem == 1
    TEST(Dintomb, letrehoz)
    {
        Dintomb d;
        d.hozzaadember("Kiss", "Belu", " Bela", "30921", "1231", 6666, 999, "Budapest", "Kek", 5);
        EXPECT_EQ(1, int(d.getvektor().size()));
        d.hozzaadember("Nagy", "Zoli", "Zoltan", "31921", "12111", 7777, 111, "Pecs", "Piros", 12);
        EXPECT_EQ(2, int(d.getvektor().size()));
        d.hozzaadember("Nagyonnagy", "Jozsi", " Jozsef", "32921", "121231231", 8888, 222, "Kaposvar", "Sarga", 19);
        d.hozzaadember("Nagyonkicsi", "Gezu", " Geza", "33921", "121231", 9999, 333, "Fot", "Fekete", 1111);
        EXPECT_EQ(4, int(d.getvektor().size()));

        EXPECT_EQ(6666, d.getvektor()[0]->getazonosito());
        EXPECT_EQ(999, d.getvektor()[0]->getcim().getirszam());

        EXPECT_EQ(string("Nagy"), d.getvektor()[1]->getembernev().getvezetek());
        EXPECT_EQ(string("Zoli"), d.getvektor()[1]->getembernev().getbece());
        EXPECT_EQ(string("Zoltan"), d.getvektor()[1]->getembernev().getkereszt());

        EXPECT_EQ(string("32921"), d.getvektor()[2]->getembertelszam().getprivat());
        EXPECT_EQ(string("121231231"), d.getvektor()[2]->getembertelszam().getmunkahelyi());

        EXPECT_EQ(string("Fot"), d.getvektor()[3]->getcim().getvaros());
        EXPECT_EQ(string("Fekete"), d.getvektor()[3]->getcim().getutca());
        EXPECT_EQ(1111, d.getvektor()[3]->getcim().gethazszam());
    }
    END
    TEST(Dintomb, torolletrehoz)
    {
        Dintomb d;
        d.hozzaadember("Kiss", "Belu", " Bela", "30921", "1231", 6666, 999, "Budapest", "Kek", 5);
        d.hozzaadember("Nagy", "Zoli", "Zoltan", "31921", "12111", 7777, 111, "Pecs", "Piros", 12);
        d.hozzaadember("Nagyonnagy", "Jozsi", " Jozsef", "32921", "121231231", 8888, 222, "Kaposvar", "Sarga", 19);
        d.hozzaadember("Nagyonkicsi", "Gezu", " Geza", "33921", "121231", 9999, 333, "Fot", "Fekete", 1111);
        EXPECT_EQ(4, int(d.getvektor().size()));

        d.torol(2);
        EXPECT_EQ(string("Nagy"), d.getvektor()[1]->getembernev().getvezetek());
        EXPECT_EQ(string("Zoli"), d.getvektor()[1]->getembernev().getbece());
        EXPECT_EQ(string("Zoltan"), d.getvektor()[1]->getembernev().getkereszt());

        EXPECT_EQ(string("Fot"), d.getvektor()[2]->getcim().getvaros());
        EXPECT_EQ(string("Fekete"), d.getvektor()[2]->getcim().getutca());
        EXPECT_EQ(1111, d.getvektor()[2]->getcim().gethazszam());

        EXPECT_EQ(3, int(d.getvektor().size()));

        d.torol(1);
        EXPECT_EQ(6666, d.getvektor()[0]->getazonosito());
        EXPECT_EQ(999, d.getvektor()[0]->getcim().getirszam());

        EXPECT_EQ(string("Fot"), d.getvektor()[1]->getcim().getvaros());
        EXPECT_EQ(string("Fekete"), d.getvektor()[1]->getcim().getutca());
        EXPECT_EQ(1111, d.getvektor()[1]->getcim().gethazszam());

        EXPECT_EQ(2, int(d.getvektor().size()));

        d.hozzaadember("Nagyonnagy", "Jozsi", " Jozsef", "32921", "121231231", 8888, 222, "Kaposvar", "Sarga", 19);
        EXPECT_EQ(string("32921"), d.getvektor()[2]->getembertelszam().getprivat());
        EXPECT_EQ(string("121231231"), d.getvektor()[2]->getembertelszam().getmunkahelyi());

        EXPECT_EQ(3, int(d.getvektor().size()));
    }
    END
    SUCCEED();
#endif // tesztem
    return 0;
}
