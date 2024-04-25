#ifndef I_FIGURA
#define I_FIGURA
#include <string>

class Ifigura{
    protected:
        std::string nazwa;
    public:
        Ifigura();
        Ifigura(std::string n);
        ~Ifigura();
        void info();
        void rysuj();
        virtual float pole()=0;
        virtual float obwod()=0;
        void wyswietl();
};

#endif