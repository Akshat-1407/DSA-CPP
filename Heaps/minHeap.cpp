#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> arr;

public:

    // Insert
    void insert(int val) {
        arr.push_back(val);
        int i = arr.size() - 1;

        while (i > 0) {
            int p = (i - 1) / 2;

            if (arr[i] < arr[p]) {
                swap(arr[i], arr[p]);
                i = p;
            }
            else
                break;
        }
    }

    // Min Heapify
    void minHeapify(int i) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < arr.size() && arr[l] < arr[smallest])
            smallest = l;

        if (r < arr.size() && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
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
            minHeapify(0);
    }

    // Build Min Heap
    void buildMinHeap() {
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
            minHeapify(i);
    }

    // Display
    void display() {
        for (int x : arr)
            cout << x << " ";

        cout << endl;
    }

    // Get Minimum
    void getMin() {
        if (arr.empty())
            cout << "Heap is empty\n";
        else
            cout << "Minimum: " << arr[0] << endl;
    }
};
