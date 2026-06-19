#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int n) {
    cout << 2*n << " ";
}

int main() {

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    cout << "Before Rotation of Array: ";
    vector<int>:: iterator it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;
    
    rotate(arr.begin(), arr.begin()+4 ,arr.end());
    
    cout << "After Rotation of Array: ";
    vector<int>:: iterator ite = arr.begin();
    while(ite != arr.end()) {
        cout << *ite << " ";
        ite++;
    }

    return 0;
}