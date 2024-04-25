//#include "Tinstrument.cpp"
#ifndef T_TRABKA
#define T_TRABKA

class Ttrabka:public Tinstrument{
    public:
        Ttrabka();
        Ttrabka(string n);
        ~Ttrabka();
        string dzwiek();
};
#endif