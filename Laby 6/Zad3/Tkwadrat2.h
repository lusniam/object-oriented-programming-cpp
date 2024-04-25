#ifndef T_KWADRAT2
#define T_KWADRAT2

class Tkwadrat2:public Tprostokat2{
    public:
        Tkwadrat2();
        Tkwadrat2(std::string n,float ap);
        ~Tkwadrat2();
        float pole();
        float obwod();
};

#endif