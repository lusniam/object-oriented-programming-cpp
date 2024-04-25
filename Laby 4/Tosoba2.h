#ifndef T_OSOBA2
#define T_OSOBA2
#include <string>
#include "Tdata.cpp"

class Tosoba2{
    private:
        std::string imie;
        std::string nazwisko;
        std::string motto;
        Tdata dataUr;
    public:
        Tosoba2();
        Tosoba2(const std::string & naz,const std::string & im,const Tdata & d);
        
        void wczytaj();
        void wyswietl();
        std::string GetNazwiskoImie();
        int roznicaWieku(Tosoba2 & partner);
        std::string dluzszeNazwisko(Tosoba2 & partner);
};
#endif