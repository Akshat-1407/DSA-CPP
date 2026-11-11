#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> arr;

public:
    // Insert
    void insert(int val) {
        arr.push_back(val);
        int i = arr.size() - 1;

        while (i > 0) {
            int p = (i - 1) / 2;

            if (arr[i] > arr[p]) {
                swap(arr[i], arr[p]);
                i = p;
            }
            else
                break;
        }
    }

    // Max Heapify
    void maxHeapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < arr.size() && arr[l] > arr[largest])
            largest = l;

        if (r < arr.size() && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
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
            maxHeapify(0);
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

        arr.clear();

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            arr.push_back(val);
        }

        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            maxHeapify(i);
    }

    // Display
    void display() {
        for (int x : arr)
            cout << x << " ";

        cout << endl;
    }

    // Get Maximum
    void getMax() {
        if (arr.empty())
            cout << "Heap is empty\n";
        else
            cout << "Maximum: " << arr[0] << endl;
    }
};
