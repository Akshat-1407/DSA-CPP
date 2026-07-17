#include <iostream>
#include <string>

using namespace std;

// Template class for Node
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(T data, Node<T>* next) {
        this->data = data;
        this->next = next;
    }
};

// Template class for List
template <typename T>
class List {
private:
    Node<T>* head;

public:
    List() {
        head = nullptr;
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "LL is Empty\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* temp = head; 

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

        Node<T>* temp = head; 
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next; 
        temp->next = nullptr; 
    }

    void insert_at_position(int position, T value) {
        if (position <= 1) {
            push_front(value);
            return;
        }

        Node<T>* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void insert_after(Node<T>* previousNode, T value) {
        if (previousNode == nullptr) {
            cout << "Invalid Insertion.\n";
            return;
        }
        
        Node<T>* nextNode = previousNode->next;
        Node<T>* newNode = new Node<T>(value);
        previousNode->next = newNode;
        newNode->next = nextNode;
    }

    T front() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return T(); // Returns default value of type T
        }
        return head->data;
    }

    T back() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return T(); // Returns default value of type T
        }
        Node<T>* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        } 
        return temp->data;       
    }

    int size() {
        int count = 0;
        Node<T>* temp = head;

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
        Node<T>* temp = head;
        while(temp != nullptr) {
            Node<T>* x = temp;
            temp = temp->next;
            delete x;
        }
        head = nullptr;
    }

    Node<T>* middle_node() {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node<T>* slow = head;
        Node<T>* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node<T>* reverse_list() {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        Node<T>* currNode = head;
        Node<T>* prevNode = nullptr;
        Node<T>* nextNode = currNode->next;

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

    bool searchLL(T x) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if(temp->data == x) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Node<T>* concatenate(Node<T>* head1) {
        if (head == nullptr && head1 == nullptr) 
            return nullptr;
        if (head == nullptr)
            return head1;
        if (head1 == nullptr)
            return head;
        
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head1;

        return head;
    }

    bool has_cycle() {
        Node<T>* fast = head;
        Node<T>* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }

    Node<T>* detect_cycle() {
        Node<T>* fast = head;
        Node<T>* slow = head;

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

    Node<T>* mergeTwoLists(Node<T>* list1, Node<T>* list2) {
        Node<T>* dummyHead = new Node<T>(T()); // Initialized with default value of T
        Node<T>* temp = dummyHead;
        
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->data < list2->data) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) {
            temp->next = list1;
        } 
        else {
            temp->next = list2;
        }

        return dummyHead->next;
    }

    Node<T>* oddEvenList() {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        Node<T>* odd = head;
        Node<T>* even = head->next;
        Node<T>* evenHead = head->next;

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
        Node<T>* temp = head;

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
    // Example usage with strings
    List<string> strList;
    strList.push_back("Hello");
    strList.push_back("Template");
    strList.push_back("World");
    
    cout << "String List: ";
    strList.display();

    // Example usage with integers
    List<int> intList;
    intList.push_front(30);
    intList.push_front(20);
    intList.push_front(10);
    
    cout << "Integer List: ";
    intList.display();

    return 0;
}