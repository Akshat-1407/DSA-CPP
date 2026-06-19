#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool countEven(int n) {
    return n % 2 == 0;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 8};

    int ans = count_if(arr.begin(), arr.end(), countEven);

    cout << ans;
    
    return 0;
}