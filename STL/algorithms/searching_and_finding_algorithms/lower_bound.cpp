#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {10, 20, 30, 40, 50, 60};

    int target = 15;

    auto it = lower_bound(arr.begin(), arr.end(), target);

    cout << "Lower Bound: " << *it;

    return 0;
}