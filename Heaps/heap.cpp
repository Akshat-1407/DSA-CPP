#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> arr;
    bool isMax;

public:
    Heap(bool maxHeap = true) {
        isMax = maxHeap;
    }

    // Insert element
    void insert(int val) {
        arr.push_back(val);
        int i = arr.size() - 1;

        while (i > 0) {
            int p = (i - 1) / 2;

            if (isMax) {
                if (arr[i] > arr[p])
                    swap(arr[i], arr[p]);
                else
                    break;
            }
            else {
                if (arr[i] < arr[p])
                    swap(arr[i], arr[p]);
                else
                    break;
            }

            i = p;
        }
    }

    // Heapify
    void heapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (isMax) {
            if (l < arr.size() && arr[l] > arr[largest])
                largest = l;

            if (r < arr.size() && arr[r] > arr[largest])
                largest = r;
        }
        else {
            if (l < arr.size() && arr[l] < arr[largest])
                largest = l;

            if (r < arr.size() && arr[r] < arr[largest])
                largest = r;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Delete root
    void deleteRoot() {
        if (arr.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty())
            heapify(0);
    }

    // Get root
    void getRoot() {
        if (arr.empty())
            cout << "Heap is empty\n";
        else
            cout << "Root: " << arr[0] << endl;
    }

    // Display
    void display() {
        if (arr.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        for (int x : arr)
            cout << x << " ";

        cout << endl;
    }

    // Build heap
    void buildHeap() {
        int n, val;

        cout << "Enter number of elements: ";
        cin >> n;

        if (n < 0) {
            cout << "Invalid size\n";
            return;
        }

        arr.clear();

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            arr.push_back(val);
        }

        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }
};

int main() {
    int choice, val, type;

    cout << "1. Max Heap\n2. Min Heap\n";
    cout << "Choose heap type: ";
    cin >> type;

    Heap h(type == 1);

    do {
        cout << "\n1. Insert\n2. Delete Root\n3. Display\n";
        cout << "4. Get Root\n5. Build Heap\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
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
                h.getRoot();
                break;

            case 5:
                h.buildHeap();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
