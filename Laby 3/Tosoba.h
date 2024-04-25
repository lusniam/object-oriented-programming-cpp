#ifndef T_OSOBA
#define T_OSOBA
#include <string>

struct Tdata{
    int d;
    int m;
    int r;
};

class Tosoba{
    private:
        std::string imie;
        char nazwisko[20]; //lancuch typu cstring
        Tdata data;
    public:
        Tosoba(); // konstruktor domyslny
        Tosoba(const std::string & im,const char* naz,Tdata dat); //konstruktor z parametrami przeciazony
        ~Tosoba(); // dekonstruktor

        void wczytaj();
        void info(int rok); // przeciazona metoda
        void info();
        void wyswietl(int rok); // przeciazona metoda
        void wyswietl();
};
#endif