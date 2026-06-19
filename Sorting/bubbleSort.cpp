#include <iostream>
#include <vector>

using namespace std;

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


int main() {
    vector<int> arr = {2, 8, 9, 4, 7, 6, 3, 1, 0, 5};

    bubbleSort(arr);

    for(int e: arr) 
        cout << e << " ";

    return 0;
}
