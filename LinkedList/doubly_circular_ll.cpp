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

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtHead(int value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // Insert at end
    void insertAtTail(int value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;
    }

    // Insert after a value
    void insertAfter(int target, int value) {

        if (head == nullptr)
            return;

        Node* curr = head;

        do {

            if (curr->data == target) {

                Node* newNode = new Node(value);

                newNode->next = curr->next;
                newNode->prev = curr;

                curr->next->prev = newNode;
                curr->next = newNode;

                return;
            }

            curr = curr->next;

        } while (curr != head);

        cout << "Target not found\n";
    }

    // Delete by value
    void deleteNode(int value) {

        if (head == nullptr)
            return;

        Node* curr = head;

        do {

            if (curr->data == value) {

                // Only one node
                if (curr->next == curr) {
                    delete curr;
                    head = nullptr;
                    return;
                }

                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                if (curr == head)
                    head = curr->next;

                delete curr;
                return;
            }

            curr = curr->next;

        } while (curr != head);

        cout << "Value not found\n";
    }

    // Search
    bool search(int key) {

        if (head == nullptr)
            return false;

        Node* curr = head;

        do {

            if (curr->data == key)
                return true;

            curr = curr->next;

        } while (curr != head);

        return false;
    }

    // Count nodes
    int size() {

        if (head == nullptr)
            return 0;

        int count = 0;
        Node* curr = head;

        do {
            count++;
            curr = curr->next;
        } while (curr != head);

        return count;
    }

    // Forward traversal
    void displayForward() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = head;

        do {
            cout << curr->data << " <-> ";
            curr = curr->next;
        } while (curr != head);

        cout << "(HEAD)\n";
    }

    // Backward traversal
    void displayBackward() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* tail = head->prev;
        Node* curr = tail;

        do {
            cout << curr->data << " <-> ";
            curr = curr->prev;
        } while (curr != tail);

        cout << "(TAIL)\n";
    }

    // Destructor
    ~DoublyCircularLinkedList() {

        if (head == nullptr)
            return;

        Node* curr = head->next;

        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        delete head;
    }
};

int main() {

    DoublyCircularLinkedList dcll;

    dcll.insertAtHead(20);
    dcll.insertAtHead(10);

    dcll.insertAtTail(30);
    dcll.insertAtTail(40);

    cout << "Forward Traversal:\n";
    dcll.displayForward();

    cout << "\nBackward Traversal:\n";
    dcll.displayBackward();

    dcll.insertAfter(20, 25);

    cout << "\nAfter inserting 25 after 20:\n";
    dcll.displayForward();

    dcll.deleteNode(30);

    cout << "\nAfter deleting 30:\n";
    dcll.displayForward();

    cout << "\nSize: " << dcll.size() << endl;

    cout << "Search 25: "
         << (dcll.search(25) ? "Found" : "Not Found")
         << endl;

    return 0;
}