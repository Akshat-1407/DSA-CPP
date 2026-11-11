#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int key) {
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(vector<int> arr, int key, int idx) {
    int size = arr.size();

    if (idx == size) {
        return -1;
    }
    else if (arr[idx] == key) {
        return idx;
    }
    
    return linearSearchRecursive(arr, key, idx + 1);
}

int main() {
    vector<int> arr = {2, 5, 7, 9, 3, 4, 6};
    int key = 99;

    int index = linearSearch(arr, key);
    int indexRecursive = linearSearchRecursive(arr, key, 0);

    cout << key << " is present at index " << index << endl;

    cout << key << " is present at index " << indexRecursive << endl;

    return 0;
}
