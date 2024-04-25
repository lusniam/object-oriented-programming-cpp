#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//11.1
template <typename T>
bool czy_palindrom(const T& t, int dlugosc)
{
    for(int i=0;2*i<=dlugosc;i++){
        if(t[i]!=t[dlugosc-1-i]){
            return false;
        }
    }
    return true;
}

void Zad1(){
    char *tekst1 = "anilina";
    char tekst2[] = "Taki sobie napis";
    string tekst3("malajalam");
    int tab1[] = {1, 2, 3, 6, 3, 2, 1};
    int tab2[] = {1, 2, 3, 4, 4, 2, 1};
    char tab3[] = {'r', 'o', 't', 'a', 't', 'o', 'r'};

    cout<<"tekst1: "<<czy_palindrom(tekst1,7)<<endl;
    cout<<"tekst2: "<<czy_palindrom(tekst2,16)<<endl;
    cout<<"tekst3: "<<czy_palindrom(tekst3,9)<<endl;
    cout<<"tab1: "<<czy_palindrom(tab1,7)<<endl;
    cout<<"tab2: "<<czy_palindrom(tab2,7)<<endl;
    cout<<"tab3: "<<czy_palindrom(tab3,7)<<endl;
}

//11.2
template <class typ>
class tab{
    private:
        typ t[10];
    public:
        void Wczytaj(typ input[]){
            for(int i=0;i<10;i++){
                t[i]=input[i];
            }
        }
        void Drukuj(){
            cout<<"Zawartosc tabeli:"<<endl;
            for(int i=0;i<10;i++){
                cout<<i+1<<": "<<t[i]<<endl;
            }
        }
};

struct Tstudent{
    string nazwisko;
    int ocena;
};

template <>
class tab<Tstudent>{
     private:
        Tstudent t[10];
    public:
        void Wczytaj(Tstudent input[]){
            for(int i=0;i<10;i++){
                t[i]=input[i];
            }
        }
        void Drukuj(){
            cout<<"Zawartosc tabeli:"<<endl;
            for(int i=0;i<10;i++){
                cout<<i+1<<": "<<t[i].nazwisko<<", ocena: "<<t[i].ocena<<endl;
            }
        }
};

void Zad2(){
    tab<int> tabInt;
    tab<float> tabFloat;
    tab<string> tabPanstwa;
    tab<Tstudent> tabTstudent;
    
    int Tint[] = {1,2,3,4,5,6,7,8,9,10};
    float Tfloat[] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
    string Tpanstwa[] = {"Polska","Litwa","Lotwa","Bialorus","Ukraina","Slowacja","Czechy","Niemcy","Szwajcaria","Slowenia"};
    Tstudent Tstd[10];
    for(int i=0;i<10;i++){
        Tstd[i].nazwisko="Student"+to_string(i+1);
        Tstd[i].ocena=1+rand()%6;
    }

    tabInt.Wczytaj(Tint);
    tabFloat.Wczytaj(Tfloat);
    tabPanstwa.Wczytaj(Tpanstwa);
    tabTstudent.Wczytaj(Tstd);
    
    tabInt.Drukuj();
    tabFloat.Drukuj();
    tabPanstwa.Drukuj();
    tabTstudent.Drukuj();
}

//11.3
vector<int> lotto(int polaK,int ile){
    vector<int> liczby;
    for(int i=1;i<=49;i++){
        liczby.push_back(i);
    }
    vector<int> wynik;
    for(int i=0;i<polaK;i++){
        random_shuffle(liczby.begin(),liczby.end());
        for(int j=0;j<ile;j++){
            wynik.push_back(liczby.at(j));
        }
    }
    return wynik;
}

void Zad3(){
    int polaK=2;
    int ile=6;
    vector<int> liczby=lotto(polaK,ile);
    for(int i=0;i<polaK;i++){
        cout<<"Kupon "<<i+1<<": ";
        for(int j=0;j<ile;j++){
            cout<<liczby.at(i*ile+j)<<",";
        }
        cout<<endl;
    }
}

int main(){
    srand(time(0));
    //Zad1();
    //Zad2();
    Zad3();
    return 0;
}
