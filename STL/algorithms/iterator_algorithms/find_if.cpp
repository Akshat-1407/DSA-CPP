#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkEven(int n) {
    if (n == 1) 
        return false;
    else
        return n % 2 == 0;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    auto it = find_if(arr.begin(), arr.end(), checkEven);
    
    if(it != arr.end()) {
        cout << "Element found: " << *it << endl;  // returns the iterator of the first element that fulfills the criteria of the function.
    }
    else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}