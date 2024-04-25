#include <iostream>
#include "tdzialania.cpp"
#include "tpracownik.cpp"
#include "tstudent.cpp"

void Zad2(){
    Tdzialania liczby;
    liczby.podajDane();
    liczby.wyswietl();
    system("pause");
}

void Zad3(){
    Tpracownik pracownik1, pracownik2;
    pracownik1.wczytaj();
    pracownik2.wczytaj();
    pracownik1.wyswietl();
    pracownik2.wyswietl();
    system("pause");
}

void Zad4(){
    Tstudent student1, student2;
    student1.wczytaj();
    student2.wczytaj();
    student1.wyswietl();
    student2.wyswietl();
    system("pause");
}

int main(){
    int wybor;
    do{
        std::cout<<"Podaj numer zadania (2-4) lub wpisz 5, aby wyjsc z programu: ";
        std::cin>>wybor;
        switch(wybor){
            case 2: {Zad2(); break;}
            case 3: {Zad3(); break;}
            case 4: {Zad4(); break;}
            default: break;
        }
        system("cls");
    }while (wybor!=5);
    return EXIT_SUCCESS;
}