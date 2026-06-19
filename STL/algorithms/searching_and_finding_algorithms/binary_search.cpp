#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {1, 3, 8, 9, 14, 15, 17, 20};

    int target = 15;
    bool exists = binary_search(arr.begin(), arr.end(), target);

    if(exists) {
        cout << "Target is present in the array";
    }
    else {
        cout << "Target is not Present in the array";
    }

    return 0;
}