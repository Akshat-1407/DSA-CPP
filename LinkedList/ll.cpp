#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp->next != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* n = new Node(10);
    print(n);

    // insertAtHead()

    return 0;
}