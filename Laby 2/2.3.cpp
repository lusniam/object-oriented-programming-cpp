#include <iostream>
#include "tpracownik.cpp"

using namespace std;

int main(){
    //3 zadeklaruj obiekt danej klasy
    Tpracownik pracownik1, pracownik2;

    //4 wykonaj metody dla danego obiektu
    pracownik1.wczytaj();
    pracownik2.wczytaj();
    pracownik1.wyswietl();
    pracownik2.wyswietl();
    system("pause");
    return EXIT_SUCCESS;
}