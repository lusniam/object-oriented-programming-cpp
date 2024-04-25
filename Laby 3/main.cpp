#include "Tosoba.cpp"
#include "Ttrojkat.cpp"
#include "Tsamochod.cpp"

void Zad1(){
    Tosoba osoba;
    {
        std::cout<<"Blok wewnetrzny"<<std::endl;
        Tdata data1={20,1,2000};
        Tosoba osoba2("jan","kowalski",data1);
        osoba2.wyswietl();
        osoba2.wyswietl(2023);
        osoba2.info();
        osoba2.info(2023);
    }std::cout<<"Koniec wewnetrznego bloku"<<std::endl;
    osoba.wczytaj();
    osoba.wyswietl();
    osoba.wyswietl(2023);
    osoba.info();
    osoba.info(2023);
}

void Zad2(){
    //praca na wskazniku
    Tosoba* wsk=new Tosoba;
    wsk->wczytaj();
    wsk->wyswietl();
    wsk->wyswietl(2023);
    wsk->info();
    wsk->info(2023);
    delete wsk;

    //praca na referencji
    Tosoba osoba1;
    Tosoba &osoba2=osoba1;

    osoba2.wyswietl();
    osoba2.wczytaj();
    osoba1.wyswietl();

    Tosoba osoba4=osoba1;
    osoba4.wyswietl();
}

void Zad3(){
    Ttrojkat trojkat;
    trojkat.wczytaj();
    trojkat.wyswietl();
}

void Zad4(){
    Tsamochod samochod;
    Tsamochod & samochod_r=samochod;
    samochod_r.wprowadzDane();
    samochod.wyswietlDane();
    samochod_r.zwiekszStanL(20000);
    samochod.wyswietlDane();

    Tsamochod samochod2(samochod);
    samochod2.wyswietlDane();
}

int main(){
    int wybor;
    do{
        std::cout<<"Podaj numer zadania (1-4) lub wpisz 5, aby wyjsc z programu: ";
        std::cin>>wybor;
        switch(wybor){
            case 1: {Zad1(); break;}
            case 2: {Zad2(); break;}
            case 3: {Zad3(); break;}
            case 4: {Zad4(); break;}
            default: break;
        }
    }while (wybor!=5);
    return EXIT_SUCCESS;
}