#include <iostream>
using namespace std;

class Cvector {
private:
    int* vector;
    int* tail;
    int size;
public:
    Cvector() {
        size = 5;
        vector = new int[size];
        tail = vector;
    }
    void push_back(int data);
    void pop_back();
    void print_vector();
};

void Cvector::push_back(int data) {
    if (tail - vector < size) {
        *tail = data; 
        tail++;
    }
    else {
        size = size + 5;
        int* vector2 = new int[size];
        int* temp = vector2;
        for (int* i = vector; i < tail; i++) {
            *temp = *i;
            temp++;
        }
        tail = temp;
        delete[] vector;
        vector = vector2;
    }
}

void Cvector::pop_back() {
    
}


void Cvector::print_vector() {
    for (int* i = vector; i < tail; i++) {
        cout << *i << endl;
    }
}

int main() {
    Cvector vector;
    vector.push_back(5);
    vector.push_back(4);
    vector.push_back(3);
    vector.push_back(6);
    vector.push_back(7);

    vector.print_vector();

    return 0;
}