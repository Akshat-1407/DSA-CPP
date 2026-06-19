#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int n) {
    cout << 2*n << " ";
}

int main() {

    vector<int> arr = {5, 9, 1, 4, 3, 7, 6, 8};
    
    // sorting in ascending order
    sort(arr.begin(), arr.end());

    cout << "Ascending Sort: ";
    vector<int>:: iterator it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    // sorting in descending using std::reverse
    reverse(arr.begin(), arr.end());
    
    cout << "Descending Sort: ";
    vector<int>:: iterator ite = arr.begin();
    while(ite != arr.end()) {
        cout << *ite << " ";
        ite++;
    }

    return 0;
}