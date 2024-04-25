#include "Ttime.cpp"
#include "Tzespolona.cpp"

//funkcje do zadania 9.1
Ttime operator*(Ttime a,int N){
    int iloczyn_min=(a.godz*60+a.min)*N;
    Ttime iloczyn(iloczyn_min/60,iloczyn_min%60);
    return iloczyn;
}

bool operator==(Ttime a,Ttime b){
    int min_a=a.godz*60+a.min;
    int min_b=b.godz*60+b.min;
    return min_a==min_b;
}

//oryginalne funkcje klasy Tzespolona
Tzespolona operator-(Tzespolona a, Tzespolona b){
    Tzespolona roznica(0,0);
    roznica.rzeczywista=a.rzeczywista-b.rzeczywista;
    roznica.urojona=a.urojona-b.urojona;
    return roznica;
}

ostream & operator<<(ostream & os, const Tzespolona & z){
    string r=to_string(z.rzeczywista),u=to_string(z.urojona)+"i";
    if(z.rzeczywista==0)
        r="";
    else if(z.rzeczywista!=0&&z.urojona>0)
        r+="+";
    if(z.urojona==0)
        u="";
    os<<r<<u;
    return os;
}

//funkcje do zadania 9.2
Tzespolona operator*(Tzespolona a, Tzespolona b){
    Tzespolona iloczyn(0,0);
    iloczyn.rzeczywista=a.rzeczywista*b.rzeczywista-a.urojona*b.urojona;
    iloczyn.urojona=a.urojona*b.rzeczywista+b.urojona*a.rzeczywista;
    return iloczyn;
}

Tzespolona operator/(Tzespolona a, Tzespolona b){
    Tzespolona iloraz(0,0);
    if(b.rzeczywista==0&&b.urojona==0){
        return iloraz;
    }
    double mianownik=b.rzeczywista*b.rzeczywista+b.urojona*b.urojona;
    iloraz.rzeczywista=(a.rzeczywista*b.rzeczywista+b.urojona*b.urojona)/mianownik;
    iloraz.urojona=(a.urojona*b.rzeczywista-a.rzeczywista*b.urojona)/mianownik;
    return iloraz;
}

int main(){
    //Zadanie 9.1
    int h,m;
    cout<<"Podaj czas lotu z Paryza do Chicago:"<<endl;
    cout<<"Godz=";
    cin>>h;
    cout<<"Min=";
    cin>>m;
    Ttime lot1(h,m);
    cout<<"Podaj czas lotu z Paryza do Warszawy:"<<endl;
    cout<<"Godz=";
    cin>>h;
    cout<<"Min=";
    cin>>m;
    Ttime lot2(h,m);
    cout<<"Podaj czas oczekiwania na lot w Paryzu:"<<endl;
    cout<<"Godz=";
    cin>>h;
    cout<<"Min=";
    cin>>m;
    Ttime oczekiwanie(h,m);
    cout<<"Calkowity czas podrozy to "<<lot1+oczekiwanie+lot2<<endl;
    cout<<"Czas lotu w dwie strony z Paryza do Chicago to "<<lot1*2<<endl;
    cout<<"Czas lotu w dwie strony z Paryza do Warszawy to "<<lot2*2<<endl;
    if(lot1==lot2){
        cout<<"Te czasy sa takie same"<<endl;
    }
    else{
        cout<<"Te czasy nie sa takie same"<<endl;
    }

    //Zadanie 9.2
    int r,u;
    cout<<"Podaj liczbe 1:"<<endl;
    cout<<"Czesc rzeczywista=";
    cin>>r;
    cout<<"Czesc urojona=";
    cin>>u;
    Tzespolona liczba1(r,u);
    cout<<"Podaj liczbe 2:"<<endl;
    cout<<"Czesc rzeczywista=";
    cin>>r;
    cout<<"Czesc urojona=";
    cin>>u;
    Tzespolona liczba2(r,u);
    cout<<"Suma: "<<liczba1+liczba2<<endl;
    cout<<"Roznica: "<<liczba1-liczba2<<endl;
    cout<<"Iloczyn: "<<liczba1*liczba2<<endl;
    cout<<"Iloraz: "<<liczba1/liczba2<<endl;

    //Zadanie 9.3 zostalo wykonane w lab 8
}