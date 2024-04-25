#ifndef T_PROSTOKAT2
#define T_PROSTOKAT2

class Tprostokat2:public Ifigura{
    protected:
        float a,b;
    public:
        Tprostokat2();
        Tprostokat2(std::string n,float ap,float bp);
        ~Tprostokat2();
        float pole();
        float obwod();
};

#endif