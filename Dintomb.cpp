#include "Dintomb.h"
#include <stdio.h>
#include <typeinfo>

void Dintomb::hozzaadceg(string neve,string telefonszama, int azonja, int irszama, string varosa, string utcaja, int hazszama) {
    Ceg* uj=new Ceg(neve, telefonszama, azonja, Cim(irszama, varosa, utcaja, hazszama));
    dolgok.push_back(uj);

}

void Dintomb::hozzaadember(string vezetekneve,string beceneve,string keresztneve,string privatja, string munkahelyije, int azonja, int irszama, string varosa, string utcaja, int hazszama) {
    Ember* uj=new Ember(Embernev(vezetekneve, beceneve, keresztneve), Embertelszam(privatja, munkahelyije), azonja, Cim(irszama, varosa, utcaja, hazszama));
    dolgok.push_back(uj);
}


void Dintomb::torol(int index) {
    delete dolgok[index];
    dolgok.erase(dolgok.begin()+index);
}

void Dintomb::listazazon(){
    int *azontomb= new int[dolgok.size()];
    for(size_t i=0; i <dolgok.size(); i++){
        azontomb[i]=dolgok[i]->getazonosito();
    }
    if(dolgok.size()>1){
        for(size_t i=0; i<dolgok.size()-1; i++){
            size_t mini=i;
            for(size_t j=i+1; j<dolgok.size(); j++){
                if (azontomb[j]<azontomb[mini]){
                    mini=j;
                }
            }

            if(mini!=i){
                int temp = azontomb[mini];
                azontomb[mini]=azontomb[i];
                azontomb[i] = temp;
            }
        }
    }
    for(size_t i=0; i< dolgok.size(); i++){
        for(size_t j=0; j<dolgok.size(); j++){
            if(azontomb[i]==dolgok[j]->getazonosito()){
                if(dolgok[j]->getembernev().getbece()!= "null"){
                    cout << "Nev:" << dolgok[j]->getembernev().getvezetek() << " \""<<dolgok[j]->getembernev().getbece() << "\" " << dolgok[j]->getembernev().getkereszt() << " | "
                    << "Telefonszam:" <<  dolgok[j]->getembertelszam().getmunkahelyi() << dolgok[j]->getembertelszam().getprivat() << " | "
                    << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
                }else{
                    cout << "Nev:" << dolgok[j]->getnev() << " | "
                    << "Telefonszam:" <<  dolgok[j]->gettelszam() << " | "
                    << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
                }
            }
        }
    }
    delete azontomb;
}

void Dintomb::listaznev(){
    string *nevtomb= new string[dolgok.size()];
    int *azontomb= new int[dolgok.size()];
    for(size_t i=0; i <dolgok.size(); i++){
        azontomb[i]=dolgok[i]->getazonosito();
    }
    for(size_t i=0; i <dolgok.size(); i++){
        if(dolgok[i]->getembernev().getbece()!= "null"){
            nevtomb[i]=dolgok[i]->getembernev().getvezetek();
        }else{
            nevtomb[i]=dolgok[i]->getnev();
        }
    }
    if(dolgok.size()>1){
        for(size_t i=0; i<dolgok.size()-1; i++){
            size_t mini=i;
            for(size_t j=i+1; j<dolgok.size(); j++){
                if (nevtomb[j]<nevtomb[mini]){
                    mini=j;
                }
            }

            if(mini!=i){
                string temp = nevtomb[mini];
                int temp2 = azontomb[mini];
                nevtomb[mini]=nevtomb[i];
                azontomb[mini]=azontomb[i];
                nevtomb[i] = temp;
                azontomb[i] = temp2;
            }
        }
    }
    for(size_t i=0; i< dolgok.size(); i++){
        for(size_t j=0; j<dolgok.size(); j++){
            if(azontomb[i]==dolgok[j]->getazonosito()){
                if(dolgok[j]->getembernev().getbece()!= "null"){
                    cout << "Nev:" << dolgok[j]->getembernev().getvezetek() << " \""<<dolgok[j]->getembernev().getbece() << "\" " << dolgok[j]->getembernev().getkereszt() << " | "
                    << "Telefonszam:" <<  dolgok[j]->getembertelszam().getmunkahelyi() << dolgok[j]->getembertelszam().getprivat() << " | "
                    << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
                }else{
                    cout << "Nev:" << dolgok[j]->getnev() << " | "
                    << "Telefonszam:" <<  dolgok[j]->gettelszam() << " | "
                    << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
                }
            }
        }
    }
    delete azontomb;
    delete nevtomb;
}

void Dintomb::keresazon(int a){
    bool vanilyen = false;
    int j;
    for(j=0; j<int(dolgok.size()); j++){
        if(dolgok[j]->getazonosito() == a){
            vanilyen = true;
            break;
        }
    }
    if(vanilyen){
        if(dolgok[j]->getembernev().getbece()!= "null"){
            cout << "Nev:" << dolgok[j]->getembernev().getvezetek() << " \""<<dolgok[j]->getembernev().getbece() << "\" " << dolgok[j]->getembernev().getkereszt() << " | "
            << "Telefonszam:" <<  dolgok[j]->getembertelszam().getmunkahelyi() << dolgok[j]->getembertelszam().getprivat() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }else{
            cout << "Nev:" << dolgok[j]->getnev() << " | "
            << "Telefonszam:" <<  dolgok[j]->gettelszam() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }
    }else{
        cout << "Nincs ilyen azonosito.\n";
    }
}

void Dintomb::keresnev(string n){
    bool vanilyen = false;
    int j;
    for(j=0; j<int(dolgok.size()); j++){
        if(dolgok[j]->getembernev().getbece()!= "null"){
            if(dolgok[j]->getembernev().getbece().compare(n) == 0 || dolgok[j]->getembernev().getvezetek().compare(n) == 0 || dolgok[j]->getembernev().getkereszt().compare(n) == 0){
                vanilyen = true;
                break;
            }
        }else{
            if(dolgok[j]->getnev().compare(n) == 0){
                vanilyen = true;
                break;
            }
        }
    }
    if(vanilyen){
        if(dolgok[j]->getembernev().getbece()!= "null"){
            cout << "Nev:" << dolgok[j]->getembernev().getvezetek() << " \""<<dolgok[j]->getembernev().getbece() << "\" " << dolgok[j]->getembernev().getkereszt() << " | "
            << "Telefonszam:" <<  dolgok[j]->getembertelszam().getmunkahelyi() << dolgok[j]->getembertelszam().getprivat() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }else{
            cout << "Nev:" << dolgok[j]->getnev() << " | "
            << "Telefonszam:" <<  dolgok[j]->gettelszam() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }
    }else{
        cout << "Nincs ilyen nev.\n";
    }
}

void Dintomb::kerestelszam(string t){
    bool vanilyen = false;
    int j;
    for(j=0; j<int(dolgok.size()); j++){
        if(dolgok[j]->getembernev().getbece()!= "null"){
            if(dolgok[j]->getembertelszam().getmunkahelyi().compare(t) == 0 || dolgok[j]->getembertelszam().getprivat().compare(t) == 0){
                vanilyen = true;
                break;
            }
        }else{
            if(dolgok[j]->gettelszam().compare(t) == 0){
                vanilyen = true;
                break;
            }
        }
    }
    if(vanilyen){
        if(dolgok[j]->getembernev().getbece()!= "null"){
            cout << "Nev:" << dolgok[j]->getembernev().getbece() << " \""<<dolgok[j]->getembernev().getbece() << "\" " << dolgok[j]->getembernev().getkereszt() << " | "
            << "Telefonszam:" <<  dolgok[j]->getembertelszam().getmunkahelyi() << dolgok[j]->getembertelszam().getprivat() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }else{
            cout << "Nev:" << dolgok[j]->getnev() << " | "
            << "Telefonszam:" <<  dolgok[j]->gettelszam() << " | "
            << "Cim:" << dolgok[j]->getcim().getirszam() << " " << dolgok[j]->getcim().getvaros() << " " << dolgok[j]->getcim().getutca() << " " << dolgok[j]->getcim().gethazszam() << "\n";
        }
    }else{
        cout << "Nincs ilyen telefonszam.\n";
    }
}

void Dintomb::fajlbe(){
    ifstream file("TELEFONKONYV.txt");
    if (file.is_open()){
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

        string line;
        while (getline(file, line)){
            stringstream iss(line);
            (iss>>vezetekneve>>beceneve>>keresztneve>>privatja>>munkahelyije>>azonja>>irszama>>varosa>> utcaja>>hazszama);
            if(beceneve!="0"){
                hozzaadember(vezetekneve,beceneve,keresztneve,privatja, munkahelyije, azonja, irszama, varosa , utcaja, hazszama);
            }else{
                hozzaadceg(vezetekneve,privatja, azonja, irszama, varosa , utcaja, hazszama);
            }
        }
        file.close();
    }
    else cout << "Nem sikerult megnyitni!(Beolvasas)";
}

void Dintomb::fajlki(){
    ofstream txt("TELEFONKONYV.txt");
    if(txt.is_open()){
        for(size_t i=0; i<dolgok.size(); i++){
            if(dolgok[i]->getembernev().getbece()!= "null"){
                txt << dolgok[i]->getembernev().getvezetek() << " " <<dolgok[i]->getembernev().getbece() << " " << dolgok[i]->getembernev().getkereszt() << " "
                << dolgok[i]->getembertelszam().getprivat() << " " << dolgok[i]->getembertelszam().getmunkahelyi() << " " << dolgok[i]->getazonosito()<< " "
                << dolgok[i]->getcim().getirszam() << " " << dolgok[i]->getcim().getvaros() << " " << dolgok[i]->getcim().getutca() << " " << dolgok[i]->getcim().gethazszam() << endl;
            }else{
                txt << dolgok[i]->getnev() <<" 0 0 "<< dolgok[i]->gettelszam()<< " 0 " << dolgok[i]->getazonosito()<< " "
                << dolgok[i]->getcim().getirszam() << " " << dolgok[i]->getcim().getvaros() << " " << dolgok[i]->getcim().getutca() << " " << dolgok[i]->getcim().gethazszam() << endl;
            }
        }
        txt.close();
    }
    else cout << "Nem sikerult megnyitni!(Fajlba iras)";
}

