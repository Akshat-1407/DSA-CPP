#include <iostream>
#include <vector>

using namespace std;

// Iterative
void bubbleSort(vector<int> &arr) {
    
    bool swapped;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}


// Recursive version (outer loop recursive)
void BubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Sort remaining n-1 elements
    BubbleSort(arr, n - 1);
}


// Fully recursive version (both loops recursive)
void bubble(int arr[], int n, int i) {
    if (n == 1)
        return;

    if (i == n - 1) {
        bubble(arr, n - 1, 0);
        return;
    }

    if (arr[i] > arr[i + 1])
        swap(arr[i], arr[i + 1]);

    bubble(arr, n, i + 1);
}


int main() {
    vector<int> arr = {2, 8, 9, 4, 7, 6, 3, 1, 0, 5};

    bubbleSort(arr);

    for(int e: arr) 
        cout << e << " ";

    return 0;
}
