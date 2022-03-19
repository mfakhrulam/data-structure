#include <iostream>
#define MAX 10
using namespace std;

class Stack {
    public :
        Stack();
        void cetak();
        void push(char);
        void pop();
    private :
        char arr[MAX];
        int top;
};

Stack::Stack() {
    top = -1;
    for (int i=0; i<MAX; i++)
    arr[i] = '0';
}

void Stack::cetak(){
    cout << "Isi stack : ";
    for (int i=0; i<= top; i++)
        cout << arr[i] << " "; 
    cout << "\n";
}

void Stack::push(char x) {
    if (top >= MAX-1) {
        cout << "== STACK PENUH\n";
        cout << "Elemen " << x << " tidak masuk\n";
    } else {
        top++;
        arr[top] = x;
        cout << "Elemen masuk : " << x << "\n";
    }
}

void Stack::pop() {
    if(top <= -1) cout << "== STACK KOSONG\n";
    else {
        cout << "Elemen yang di-pop : " << arr[top] << endl;
        top--;
    }
}

int main() {
    Stack stackObj;
    cout << "============\n";
    cout << "=== STACK\n\n";
    // masukkan ke stack dari huruf 'a' sampai 'g' dan cetak tiap dimasukkan
    for (char c = 'a'; c <= 'k'; c++) {
        stackObj.push(c);
        stackObj.cetak();
    }
    // pop dua huruf terakhir
    cout << "Pop empat huruf terakhir\n";
    for (int i = 0; i < 4; i++) {
        stackObj.pop();
    }
    // push char '6'
    cout << "Push 6\n";
    stackObj.push('6');
    // push char z
    cout << "Push z\n";
    stackObj.push('z');
    // cetak
    stackObj.cetak();
    return 0;
}