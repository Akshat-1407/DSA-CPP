#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {10, 20, 30, 40, 50};

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    cout << "Total Sum: " << totalSum;

    return 0;
}