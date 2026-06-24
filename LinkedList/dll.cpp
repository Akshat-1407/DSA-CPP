#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert at position (1-based indexing)
    void insertAtPosition(int position, int value) {

        if (position <= 1) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        if (temp == tail) {
            insertAtTail(value);
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete first node
    void deleteAtHead() {

        if (head == nullptr)
            return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;

        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    // Delete last node
    void deleteAtTail() {

        if (head == nullptr)
            return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
    }

    // Delete by value
    void deleteByValue(int value) {

        if (head == nullptr)
            return;

        if (head->data == value) {
            deleteAtHead();
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }

        if (temp == tail) {
            deleteAtTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    // Search
    bool search(int key) {

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // Count nodes
    int size() {

        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display forward
    void print() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Reverse DLL
    void reverse() {

        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {

            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        if (temp != nullptr) {
            temp = temp->prev;
        }

        swap(head, tail);
    }

    // Destructor
    ~DoublyLinkedList() {
        while (head != nullptr) {
            deleteAtHead();
        }
    }
};

int main() {

    DoublyLinkedList dll;

    dll.insertAtHead(20);
    dll.insertAtHead(10);

    dll.insertAtTail(30);
    dll.insertAtTail(40);

    cout << "Forward Traversal:\n";
    dll.print();

    cout << "\nBackward Traversal:\n";
    dll.print();

    dll.insertAtPosition(3, 25);

    cout << "\nAfter insertion at position 3:\n";
    dll.print();

    dll.deleteByValue(30);

    cout << "\nAfter deleting 30:\n";
    dll.print();

    cout << "\nSize: " << dll.size() << endl;

    cout << "\nSearch 25: "
         << (dll.search(25) ? "Found" : "Not Found")
         << endl;

    dll.reverse();

    cout << "\nAfter reversing:\n";
    dll.print();

    return 0;
}