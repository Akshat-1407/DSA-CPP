#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteAtHead() {
        if (head == nullptr) 
            return;

        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    

    ~List() {
        while (head != nullptr) {
            deleteAtHead();
        }
    }

};



int main() {

    List list;

    list.insertAtHead(2);
    list.insertAtHead(4);
    list.insertAtHead(6);
    list.insertAtHead(8);

    list.display();

    return 0;
}