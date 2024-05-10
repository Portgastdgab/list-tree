#include <iostream>

using namespace std;

class Clist {
private:

    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head; 
    Node* tail; 

public:
    Clist() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int);
    bool pop(int&);
    void printlist();

};

void Clist::push(int value) {
    if (head == nullptr)
    {
        head = new Node(value);
        tail = head;
    }
    else
    {
        tail->next = new Node(value);
        tail = tail->next;
    }
}


bool Clist::pop(int &val) {
    val = head->data;
    if (head == tail)
    {
        return true;
    }
    head = head->next;
    return false;
    
}

void Clist::printlist() {
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
}

int main() {
    Clist list;
    for (int i = 0; i < 11; i++)
    {
        list.push(i);
    }
    int val = NULL;
    for (int i = 0; i < 13; i++)
    {
        if (list.pop(val))
        {
            cout << "cola vacia" << endl;
        }        
        else
        {
			cout << "pop: " << val << endl;
		}
    }
    list.printlist();

    return 0;
}