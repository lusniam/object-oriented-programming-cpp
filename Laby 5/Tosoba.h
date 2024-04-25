#ifndef T_OSOBA
#define T_OSOBA
#include <string>

using namespace std;

class Tosoba{
    protected:
        string imie;
        string nazwisko;
    public:
        Tosoba();
        Tosoba(string im, string naz);
        ~Tosoba();
        void wczytaj();
        void wyswietl();
};

#endif