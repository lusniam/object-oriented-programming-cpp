#ifndef T_KWADRAT
#define T_KWADRAT

class Tkwadrat:public Tprostokat{
    public:
        Tkwadrat();
        Tkwadrat(std::string n,float ap);
        ~Tkwadrat();
        float pole();
        float obwod();
};

#endif