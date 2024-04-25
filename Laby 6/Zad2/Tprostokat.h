#ifndef T_PROSTOKAT
#define T_PROSTOKAT

class Tprostokat:public Tfigura{
    protected:
        float a,b;
    public:
        Tprostokat();
        Tprostokat(std::string n,float ap,float bp);
        ~Tprostokat();
        float pole();
        float obwod();
};

#endif