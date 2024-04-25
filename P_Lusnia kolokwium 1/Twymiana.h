#ifndef T_WYMIANA
#define T_WYMIANA
#include <string>
#include "Tcennik.cpp"

struct Tdata{
    int d;
    int m;
    int r;
};

struct Tgodzina{
    int m;
    int h;
};

class Twymiana{
    protected:
        Tdata data;
        Tgodzina godz;
        std::string nrPojazdu;
        std::string opisWymiany;
        Tcennik* cennik;
        int pozCennika;
    public:
        Twymiana(); 
        Twymiana(Tcennik* cen); //przeciazanie
        void wczytaj();
        void wyswietl();
        virtual void wyswietlKoszt();
};

#endif