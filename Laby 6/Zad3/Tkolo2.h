#ifndef T_KOLO2
#define T_KOLO2

class Tkolo2:public Ifigura{
    private:
        float r;
    public:
        Tkolo2();
        Tkolo2(std::string n,float rp);
        ~Tkolo2();
        float pole();
        float obwod();
};

#endif