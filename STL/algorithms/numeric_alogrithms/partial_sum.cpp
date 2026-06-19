#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result(arr.size());

    partial_sum(arr.begin(), arr.end(), result.begin());

    for(int e: result) {
        cout << e << " ";
    }

    return 0;
}