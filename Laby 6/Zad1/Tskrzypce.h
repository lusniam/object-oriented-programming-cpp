//#include "Ttrabka.cpp"
#ifndef T_SKRZYPCE
#define T_SKRZYPCE

class Tskrzypce: public Tinstrument{
    public:
        Tskrzypce();
        Tskrzypce(string n);
        ~Tskrzypce();
        //string dzwiek();
        virtual string dzwiek();
};
#endif