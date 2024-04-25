#include "Ttrabka.h"

Ttrabka::Ttrabka(){
    cout<<"Konstruktor domyslny klasy Ttrabka"<<endl;
    nazwa="trabka";
}

Ttrabka::Ttrabka(string n){
    cout<<"Konstruktor z parametrami klasy Ttrabka"<<endl;
    nazwa=n;
}

Ttrabka::~Ttrabka(){
    cout<<"Destruktor domyslny klasy Ttrabka"<<endl;
}

string Ttrabka::dzwiek(){
    return "tru tu tu tu";
}