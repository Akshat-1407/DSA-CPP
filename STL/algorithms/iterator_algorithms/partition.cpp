#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkEven(int n) {
    return n % 2 == 0;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Before Partition: ";
    vector<int>:: iterator it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    // partition
    auto ite = partition(arr.begin(), arr.end(), checkEven);  // Before the iterator `ite` all the elements are even 
                                                              // After the itearator `ite` all the elements are odd.
    cout << "After Partition: ";
    for(int e: arr) {
        cout << e << " ";
    }

    return 0;
}