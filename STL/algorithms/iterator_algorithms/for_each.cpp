#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDouble(int n) {
    cout << 2*n << " ";
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    for_each(arr.begin(), arr.end(), printDouble);

    return 0;
}