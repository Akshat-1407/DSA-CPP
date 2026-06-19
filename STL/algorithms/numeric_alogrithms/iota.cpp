#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr(10);

    iota(arr.begin(), arr.end(), 25);

    for(int e: arr) {
        cout << e << " ";
    }

    return 0;
}