#ifndef T_KOLO
#define T_KOLO

class Tkolo:public Tfigura{
    private:
        float r;
    public:
        Tkolo();
        Tkolo(std::string n,float rp);
        ~Tkolo();
        float pole();
        float obwod();
};

#endif