#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6, 7, 8, 9, 10};

    int innerProduct = inner_product(arr1.begin(), arr1.end(), arr2.begin(), 5);

    cout << "Inner Product: " << innerProduct;

    return 0;
}