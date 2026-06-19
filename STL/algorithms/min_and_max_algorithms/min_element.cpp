#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {10, 20, 30, 40, 50, 60};

    auto it = min_element(arr.begin(), arr.end());

    cout << "Minimum Element: " << *it;

    return 0;
}