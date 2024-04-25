#include "Klasy.cpp"

string sasiad(Tdomownik *wsk){
    string kod;
    cout<<"Podaj nowy kod: ";
    getline(cin,kod);
    wsk->setkod(kod);
    return wsk->sekret;
}

int main(){
    string imie,sekret;
    Tdomownik ojciec,matka,corka;
    cout<<"Ojciec:"<<endl;
    ojciec.wczytaj();
    cout<<"Matka:"<<endl;
    matka.wczytaj();
    cout<<"Corka:"<<endl;
    corka.wczytaj();
    Tsasiad sasiad1("Marek");
    sasiad(&ojciec);
    sasiad1.info(&ojciec);
    sasiad1.info(&matka);
    sasiad1.info(&corka);
    cout<<ojciec<<endl;
    cout<<corka<<endl;
}