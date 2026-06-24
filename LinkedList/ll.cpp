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


    void push_front(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }


    void pop_front() {
        if (head == nullptr) {
            cout << "LL is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }


    void push_back(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head; 

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }


    void pop_back() {       
        if (head == nullptr) {
            cout << "LL is Empty\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head; 
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next; 
        temp->next = nullptr; 
    }


    void insert_at_position(int position, int value) {
        if (position <= 1) {
            push_front(value);
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

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    void insert_after(Node* previousNode, int value) {
        if (previousNode == nullptr) {
            cout << "Invalid Insertion.\n";
            return;
        }
        
        Node* nextNode = previousNode->next;
        Node* newNode = new Node(value);
        previousNode->next = newNode;
        newNode->next = nextNode;
    }


    int front() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return -1;
        }
        return head->data;
    }


    int back() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return -1; 
        }
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        } 
        return temp->data;       
    }


    int size() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }


    bool empty() {
        return head == nullptr;
    }


    void clear() {
        Node* temp = head;
        while(temp != nullptr) {
            Node* x = temp;
            temp = temp->next;
            delete x;
        }
        head = nullptr;
    }


    Node* middle_node() {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    Node* reverse_list() {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* currNode = head;
        Node* prevNode = nullptr;
        Node* nextNode = currNode->next;

        while(currNode != nullptr) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if(nextNode != nullptr) {
                nextNode = currNode->next;
            }
        }
        head = prevNode;
        return head;
    }

    bool searchLL(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if(temp->data == x) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }


    Node* concatenate(Node* head1) {
        if (head == nullptr && head1 == nullptr) 
            return nullptr;
        if (head == nullptr)
            return head1;
        if (head1 == nullptr)
            return head;
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head1;

        return head;
    }


    bool has_cycle() {
        Node* fast = head;
        Node* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }


    Node* detect_cycle() {
        Node* fast = head;
        Node* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;

                while(fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }
        return nullptr;
    }


    Node* oddEvenList() {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = head->next;

        while(even != nullptr && even->next != nullptr) {

            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next; 
        }

        odd->next = evenHead;
        
        return head;
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
            pop_front();
        }
    }

};


int main() {



    return 0;
}