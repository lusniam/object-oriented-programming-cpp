#include <string>
#ifndef T_TOWAR
#define T_TOWAR

using namespace std;

class Ttowar{
    protected:
        string kod;
        string nazwa;
        float ilosc;
        float cena;
    public:
        Ttowar();
        void wczytaj();
        void wyswietl();
        float oblicz();
};

#endif