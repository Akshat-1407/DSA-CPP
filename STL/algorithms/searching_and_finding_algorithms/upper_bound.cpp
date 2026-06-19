#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {10, 20, 30, 40, 50, 60};

    int target = 20;

    auto it = upper_bound(arr.begin(), arr.end(), target);

    cout << "Upper Bound: " << *it;

    return 0;
}