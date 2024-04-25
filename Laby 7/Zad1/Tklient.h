#include <string>
#ifndef T_KLIENT
#define T_KLIENT

using namespace std;

class Tklient{
    protected:
        string NIP;
        string imie;
        string nazwisko;
    public:
        Tklient();
        void wczytaj();
        void wyswietl();
};

#endif