#include <iostream>

using namespace std;

int tamaño = 10;

class Elementor {
private:
    struct Node {
        int* vector;
        int* fin;
        Node* next;
        Node* prev;
        Node() {
            vector = new int[tamaño];
            fin = vector - 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    Elementor() {
        head = nullptr;
        tail = nullptr;
    }

    int* find(int, Node*&);
    void add(int);
    void del(int);
    void print();
};

int* Elementor::find(int value, Node*& nodo) {
    int* pass = nullptr;
    Node* current = head;
    for (; current != nullptr; current = current->next)
    {
        for (pass = current->vector; pass != (current->fin) + 1; pass++)
        {
            if (*pass >= value)
            {
                nodo = current;
                return pass;
            }
        }
        if (current->next == nullptr)
        {
            break;
        }
    }
    pass--;
    if (pass == current->vector + (tamaño - 1))
    {
        current->next = new Node();
        tail = current->next;
        tail->prev = current;
        pass = tail->vector;
        return pass;
    }
    nodo = current;
    return (pass + 1);
}

void Elementor::add(int value) {
    Node* basura = nullptr;
    if (head == nullptr)
    {
        head = new Node();
        tail = head;
        tail->fin = tail->vector;
        *(head->vector) = value;
    }

    else {
        if (tail->fin == tail->vector + (tamaño - 1))
        {
            tail->next = new Node;
            tail->next->prev = tail;
            tail = tail->next;
        }
        int* place = find(value, basura);

        if (place == (tail->fin) + 1)
        {
            *place = value;
            tail->fin++;
        }
        else
        {
            if (place == tail->vector + (tamaño - 1))
            {
                Node* temp = new Node;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
                *tail->vector = *temp->fin;
                *temp->fin = value;
            }
            else {
                Node* current = tail;
                for (int* pass = tail->fin + 1; pass != place; pass--)
                {
                    if (pass == current->vector && current->prev != nullptr)
                    {
                        current = current->prev;
                        *pass = *(current->fin);
                        pass = current->fin + 1;

                    }

                    else
                    {
                        *(pass) = *(pass - 1);
                    }
                }
                tail->fin++;
                *place = value;

            }

        }

    }
}


void Elementor::del(int value) {
    Node* current = nullptr;
    int* place = find(value, current);
    if (*place != value) {
        cout << value << " no se encuentra en el elementor" << endl;
        return;
    }

    for (int* pass = place; pass != tail->fin; pass++) {
        if (pass == current->fin && current->next != nullptr)
        {
            *pass = *(current->next->vector);
            pass = current->next->vector-1;
            current = current->next;
        }
        else
        {
            *pass = *(pass + 1);
        }

    }
    if (tail->fin == head->vector)
    {
        tail->fin--;
    }
    else if (tail->fin == tail->vector)
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    else {
        tail->fin--;
    }
    cout << value << " se ha eliminado" << endl;
}

void Elementor::print() {
    if (tail->fin == head->vector - 1)
    {
        cout << "Elementor vacio" << endl;
        return;
    }

    for (Node* current = head; current != nullptr; current = current->next)
    {
        cout << "[";
        for (int* pass = current->vector; pass != (current->fin) + 1; pass++) {
            cout << *pass << ", ";
        }
        cout << "] -> ";
    }
}


int main() {
    Elementor elementor;
    for (int i = 30; i > 0; i--)
    {
        elementor.add(i);
    }
    for (int i = 11; i < 23; i++)
    {
        elementor.del(i);
    }
    elementor.del(100);

    elementor.print();

    return 0;
}