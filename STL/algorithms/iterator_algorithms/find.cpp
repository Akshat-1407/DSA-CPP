#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    auto it = find(arr.begin(), arr.end(), 1);
    
    if(it != arr.end()) {
        cout << "Element found: " << *it << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}