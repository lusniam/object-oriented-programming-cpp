#include <iostream>
#include <string>

#ifndef T_DOMOWNIK
#define T_DOMOWNIK

using namespace std;

class Tdomownik{
    private:
        string nazwa;
        string sekret;
        static string kod;
    public:
        Tdomownik();
        static void setkod(string k);
        static string getkod();
        void wczytaj();
        void wyswietl();
        friend string sasiad(Tdomownik *wsk);
        friend class Tsasiad;
        friend ostream & operator<<(ostream & os, const Tdomownik & d);
};

#endif

#ifndef T_SASIAD
#define T_SASIAD

class Tsasiad{
    private:
        string nazwa;
    public:
        Tsasiad(string n);
        void info(Tdomownik *wsk);
};

#endif