#ifndef T_INSTRUMENT
#define T_INSTRUMENT
#include <string>

class Tinstrument
{
    protected:
        std::string nazwa;
    public:
        Tinstrument();
        Tinstrument(std::string n);
        ~Tinstrument();//wirtualny destruktor
        //std::string dzwiek();//metoda wirtualna
        virtual std::string dzwiek();
        void muzyka(int n);//n dzwieków
};
#endif