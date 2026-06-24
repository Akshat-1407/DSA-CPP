#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail; // tail->next always points to head

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at beginning
    void insertAtHead(int value) {

        Node* newNode = new Node(value);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    // Insert at end
    void insertAtTail(int value) {

        Node* newNode = new Node(value);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert after a specific value
    void insertAfter(int target, int value) {

        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = tail->next;

        do {
            if (curr->data == target) {

                Node* newNode = new Node(value);

                newNode->next = curr->next;
                curr->next = newNode;

                if (curr == tail)
                    tail = newNode;

                return;
            }

            curr = curr->next;

        } while (curr != tail->next);

        cout << "Target not found\n";
    }

    // Delete a node by value
    void deleteNode(int value) {

        if (tail == nullptr)
            return;

        Node* prev = tail;
        Node* curr = tail->next;

        do {

            if (curr->data == value) {

                // Single node case
                if (curr == prev) {
                    delete curr;
                    tail = nullptr;
                    return;
                }

                prev->next = curr->next;

                if (curr == tail)
                    tail = prev;

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != tail->next);

        cout << "Value not found\n";
    }

    // Search
    bool search(int key) {

        if (tail == nullptr)
            return false;

        Node* curr = tail->next;

        do {

            if (curr->data == key)
                return true;

            curr = curr->next;

        } while (curr != tail->next);

        return false;
    }

    // Count nodes
    int size() {

        if (tail == nullptr)
            return 0;

        int count = 0;
        Node* curr = tail->next;

        do {
            count++;
            curr = curr->next;
        } while (curr != tail->next);

        return count;
    }

    // Display
    void display() {

        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = tail->next;

        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);

        cout << "(HEAD)\n";
    }

    // Destructor
    ~CircularLinkedList() {

        if (tail == nullptr)
            return;

        Node* head = tail->next;
        tail->next = nullptr; // break the circle

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    CircularLinkedList cll;

    cll.insertAtHead(20);
    cll.insertAtHead(10);

    cll.insertAtTail(30);
    cll.insertAtTail(40);

    cout << "Initial List:\n";
    cll.display();

    cll.insertAfter(20, 25);

    cout << "\nAfter inserting 25 after 20:\n";
    cll.display();

    cll.deleteNode(30);

    cout << "\nAfter deleting 30:\n";
    cll.display();

    cout << "\nSize: " << cll.size() << endl;

    cout << "Search 25: "
         << (cll.search(25) ? "Found" : "Not Found")
         << endl;

    return 0;
}