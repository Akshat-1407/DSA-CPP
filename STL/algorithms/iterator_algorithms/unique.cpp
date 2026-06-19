#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int n) {
    cout << 2*n << " ";
}

int main() {

    vector<int> arr = {1, 1, 5, 6, 3, 6, 3, 9, 4, 1};
    
    // sorting in ascending order
    sort(arr.begin(), arr.end());

    cout << "Normal Sort: ";
    vector<int>:: iterator it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    // sorting in descending using std::reverse
    auto ite = unique(arr.begin(), arr.end()); // Before the iterator `ite` all the elements are unique 
                                               // After the itearator `ite` all the elements are duplicates.

    cout << "Unique Sort: ";

    arr.erase(ite, arr.end());

    for (int e: arr) {
        cout << e << " ";
    }

    return 0;
}