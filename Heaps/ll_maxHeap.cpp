#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        left = right = parent = NULL;
    }
};

class MaxHeap {
    Node* root;

public:
    MaxHeap() {
        root = NULL;
    }

    // Insert
    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                newNode->parent = temp;
                break;
            }
            else
                q.push(temp->left);

            if (temp->right == NULL) {
                temp->right = newNode;
                newNode->parent = temp;
                break;
            }
            else
                q.push(temp->right);
        }

        // Heapify Up
        Node* curr = newNode;

        while (curr->parent != NULL &&
               curr->data > curr->parent->data) {
            swap(curr->data, curr->parent->data);
            curr = curr->parent;
        }
    }

    // Max Heapify Down
    void maxHeapify(Node* node) {
        if (node == NULL)
            return;

        Node* largest = node;

        if (node->left != NULL &&
            node->left->data > largest->data)
            largest = node->left;

        if (node->right != NULL &&
            node->right->data > largest->data)
            largest = node->right;

        if (largest != node) {
            swap(node->data, largest->data);
            maxHeapify(largest);
        }
    }

    // Delete Root
    void deleteRoot() {
        if (root == NULL) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Deleted: " << root->data << endl;

        queue<Node*> q;
        q.push(root);

        Node* last = NULL;

        // Find last node
        while (!q.empty()) {
            last = q.front();
            q.pop();

            if (last->left != NULL)
                q.push(last->left);

            if (last->right != NULL)
                q.push(last->right);
        }

        if (last == root) {
            delete root;
            root = NULL;
            return;
        }

        root->data = last->data;

        Node* p = last->parent;

        if (p->left == last)
            p->left = NULL;
        else
            p->right = NULL;

        delete last;

        maxHeapify(root);
    }

    // Build Max Heap
    void buildMaxHeap() {
        int n, val;

        cout << "Enter number of elements: ";
        cin >> n;

        if (n < 0) {
            cout << "Invalid size\n";
            return;
        }

        clear(root);
        root = NULL;

        cout << "Enter elements: ";

        for (int i = 0; i < n; i++) {
            cin >> val;
            insert(val);
        }
    }

    // Display Level Order
    void display() {
        if (root == NULL) {
            cout << "Heap is empty\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }

    // Get Maximum
    void getMax() {
        if (root == NULL)
            cout << "Heap is empty\n";
        else
            cout << "Maximum: " << root->data << endl;
    }

    // Free memory
    void clear(Node* node) {
        if (node == NULL)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~MaxHeap() {
        clear(root);
    }
};

int main() {
    MaxHeap h;
    int ch, val;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete Root";
        cout << "\n3. Display";
        cout << "\n4. Get Maximum";
        cout << "\n5. Build Max Heap";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                h.insert(val);
                break;

            case 2:
                h.deleteRoot();
                break;

            case 3:
                h.display();
                break;

            case 4:
                h.getMax();
                break;

            case 5:
                h.buildMaxHeap();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (ch != 6);

    return 0;
}
