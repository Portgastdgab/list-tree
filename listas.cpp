#include <iostream>

using namespace std;

// Declaración de la clase Clist
class Clist {
private:
    // Estructura para los nodos de la lista
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value, Node* front) {
            data = value;
            next = nullptr;
            prev = front;
        }
    };

    Node* head; // Puntero al primer nodo de la lista
    Node* tail; // Puntero al último nodo de la lista, renombrado para claridad

public:
    Clist() {
        head = nullptr;
        tail = nullptr; 
    }

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void printlist();

};

void Clist::push_back(int value) {
    if (head == nullptr)
    {
        head = new Node(value, nullptr);
        tail = head;
    }
    else
    {
        tail->next = new Node(value, tail);
        tail = tail->next;
    }
}

void Clist::push_front(int value) {
    head->prev = new Node(value, nullptr);
    head->prev->next = head;
    head = head->prev;
}

void Clist::pop_back() {

    tail = tail->prev;
    tail->next = nullptr;
    delete tail->next;

}

void Clist::pop_front() {
    
    head = head->next;
    head->prev = nullptr;
    delete head->prev;

}

void Clist::printlist() {
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

int main() {
    Clist list;
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_front(7);
    list.push_front(6);
    list.push_front(5);
    list.pop_back();
    list.pop_front();
    list.pop_back();
    list.pop_front();
    list.push_back(0);
    list.push_front(0);
    list.printlist();

    return 0;
}