#include <iostream>
using namespace std;

class Pila {
    int elem[10];
    int* top = elem;

public:

    bool push(int a);
    bool pop(int a);
    void print();
};

bool Pila::push(int a) {
    if (top - elem < 10) {
        *top = a;
        top++;
        return true;
    }
    pop(a);
    return false;
}

bool Pila::pop(int a) {
    top--;
    *top = a;
    top++;
    return true;
}

void Pila::print() {
    for (int i = 0; i < (top - elem); i++)
    {
        cout << elem[i] << " ";
    }
    cout << endl;
}

int main() {
    Pila pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);
    pila.push(6);
    pila.push(7);
    pila.push(8);
    pila.push(9);
    pila.push(10);
    pila.push(11);     
    
    pila.print();
    return 0;
}