#include <iostream>
using namespace std;

class Angka {
    public:
        Angka(int num0=0) : num(num0){}
        int get_num();
        void set_num(int n);
        void balik_recur(int n);
        int balik_iter(int n);
    private:
        int num;
        int num_balik;
};

void Angka::set_num(int n){
    num = n;
}

int Angka::get_num(){
    return num;
}

int Angka::balik_iter(int n){
    num_balik = 0;
    while (n>0) {
        num_balik = num_balik * 10 + n%10;
        n = n/10;
    }
    return num_balik;
}

void Angka::balik_recur(int n){
    if (n < 10) cout << n;
    else {
        cout << n % 10;
        Angka::balik_recur(n/10);
    }
}

int main(){
    Angka test, test2(234);
    int n;
    cout << "Masukkan integer yang akan dibalik : ";
    cin >> n;
    test.set_num(n);
    cout << "Integer sebelum dibalik : " << test.get_num() << endl;
    cout << "Integer setelah dibalik";
    cout << "\nSecara Iteratif : " << test.balik_iter(test.get_num());
    cout << "\nSecara Rekursif : ";
    test.balik_recur(test.get_num());
    return 0;
}