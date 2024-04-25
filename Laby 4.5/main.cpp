#include "Tosoba3.cpp"

int main(){
    string ja="nazw";
    cout<<"adres ja: "<<&ja<<endl;
    Tosoba3 osoba1(ja);
    osoba1.getNazwisko();
    cout<<"adres osoba1: "<<&osoba1<<endl;
    cout<<ja<<endl;

    return EXIT_SUCCESS;
}