#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int n) {
    cout << 2*n << " ";
}

int main() {

    vector<int> arr = {5, 9, 1, 4, 3, 7, 6, 8};

    cout << "Original Array: ";
    vector<int>:: iterator it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;
    
    reverse(arr.begin(), arr.end());
    
    cout << "Reversed Array: ";
    vector<int>:: iterator ite = arr.begin();
    while(ite != arr.end()) {
        cout << *ite << " ";
        ite++;
    }

    return 0;
}