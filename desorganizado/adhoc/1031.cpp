#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size=0;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    int get_size(){
        return size;
    }
    void remove(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                }

                delete current;
                return; 
            }

            current = current->next;
        }
        size--;
    }
    void printForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
};

int main() {
    int num, ponteiro, acumulador;
    DoublyLinkedList myList;
    cin >> num;
    for(int i =1; i <=num;i++){myList.append(i);}
    ponteiro=1;
    acumulador=5;
    while(myList.get_size()!=1){
        cout << ponteiro << endl;
        myList.remove(ponteiro);
        if(ponteiro+acumulador==num){
            acumulador++;
            ponteiro=acumulador;
        }else if(ponteiro+acumulador>num){
            acumulador++;
            ponteiro = acumulador - (num-ponteiro);
        }else{
            ponteiro+=acumulador;
        }
    }
    myList.printForward();

    return 0;
}
