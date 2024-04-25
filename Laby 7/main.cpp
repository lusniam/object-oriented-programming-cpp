#include "Zad1/Tfaktura.cpp"
#include "Zad2/Tstudent.cpp"
#include "Zad2/TpracaDyplomowa.cpp"
#include "Zad2/TegzaminDyplomowy.cpp"

void Zad1(){
    Tklient* k1=new Tklient;
    Tklient* k2=new Tklient;
    k1->wczytaj();
    k2->wczytaj();
    Tfaktura f1(5,k1),f2(3,k2),f3(6,k2);
    f1.wczytaj();
    system("clear");
    f1.wyswietl();
}

void Zad2(){
    Tpromotor* promotor1=new Tpromotor;
    promotor1->wczytaj();
    cout<<"Podaj liczbe studentow: ";
    int liczbaS;
    cin>>liczbaS;
    Tstudent** student=new Tstudent* [liczbaS];
    for(int i=0;i<liczbaS;i++){
        student[i]=new Tstudent;
        student[i]->wczytaj();
    }
    TpracaDyplomowa pd1(liczbaS,promotor1,student);
    pd1.wczytaj();
    TegzaminDyplomowy eg1(liczbaS,student);
    eg1.wczytaj();
    
    system("clear");
    pd1.wyswietl();
    cout<<endl;
    eg1.wyswietl();
    cout<<endl;
    for(int i=0;i<liczbaS;i++){
        student[i]->wyswietl();
    }
    cout<<endl;
}

int main(){
    int wybor;
    do{
        cout<<"Wybierz:"<<endl;
        cout<<"1) - Zad 7.1"<<endl;
        cout<<"2) - Zad 7.2"<<endl;
        cout<<"0) - Wyjscie z programu"<<endl;
        cin>>wybor;
        string w;
        if(wybor==1){getline(cin,w);Zad1();}
        else if (wybor==2)    Zad2();
    }while(wybor!=0);
    return 0;
}
