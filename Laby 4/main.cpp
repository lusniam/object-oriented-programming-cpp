#include "Tosoba2.cpp"
#include "TosobaS.cpp"

void Zad1(){
    /*Tdata data;
    data.wczytaj();
    data.wyswietl();
    Tdata data2(10,3,2020);
    data2.wyswietl();*/

    Tosoba2 osoba,partner;
    osoba.wczytaj();
    partner.wczytaj();
    osoba.wyswietl();
    cout<<osoba.GetNazwiskoImie()<<endl;
    cout<<osoba.dluzszeNazwisko(partner)<<endl;
    cout<<osoba.roznicaWieku(partner)<<endl;
}

void Zad2(){
    cout<<"Liczba obiektow: "<<TosobaS::ile()<<endl;
    cout<<"Osoby sa z kraju "<<TosobaS::getKraj()<<endl;
    TosobaS osoba1;
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    TosobaS osoba2("Kowalski","Jan",13);
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    TosobaS *osoba3;
    osoba3 = new TosobaS;
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    {
        TosobaS osoba4;
        cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    }
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    TosobaS &osoba4=osoba2;
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    TosobaS osoba5(osoba2);
    cout<<"Liczba obiektow: "<<osoba1.ile()<<endl;
    cout<<osoba5.getKraj()<<endl;
}

void Zad3(){
    int n;
    cout<<"Podaj liczbe osob w notesie: ";
    cin>>n;
    Tosoba2* notes;
    notes = new Tosoba2[n];
    for(int i=0;i<n;i++){
        notes[i].wczytaj();
    }
    cout<<"Tak wyglada twoj notes:"<<endl;
    for(int i=0;i<n;i++){
        notes[i].wyswietl();
        cout<<endl;
    }
    delete [] notes;
}

int main(){
    int wybor;
    do{
        cout<<"Wybierz numer zadania(1-3), lub wpisz 0 aby zakonczyc program: ";
        cin>>wybor;
        switch(wybor){
            case 1:{Zad1(); break;}
            case 2:{Zad2(); break;}
            case 3:{Zad3(); break;}
            default: break;
        }
    }while(wybor!=0);
    return EXIT_SUCCESS;
}