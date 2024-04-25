#ifndef T_FIGURA
#define T_FIGURA
#include <string>

class Tfigura{
    protected:
        std::string nazwa;
    public:
        Tfigura();
        Tfigura(std::string n);
        ~Tfigura();
        void info();
        void rysuj();
        virtual float pole();
        virtual float obwod();
        void wyswietl();
};

#endif