#include <iostream>
using namespace std;

bool BinBus(int* ini, int* fin, /*int*& pos,*/ int key) {
    while (ini <= fin) {
        int* mid = ini + (fin - ini) / 2;

        // Comprueba si el elemento objetivo está presente en el medio
        if (*mid == key)
            return true;

        // Si el elemento objetivo es mayor, ignora la mitad izquierda
        if (*mid < key)
            ini = mid + 1;

        // Si el elemento objetivo es menor, ignora la mitad derecha
        else
            fin = mid - 1;
    }

    // Si el elemento objetivo no está presente en el array
    return false;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    if (BinBus(arr, arr+10, 15))
    {
        cout << "existe" << endl;
    }
    else
    {
        cout << "no existe" << endl;
    }
    return 0;
}