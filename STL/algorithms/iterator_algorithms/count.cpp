#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 9, 5, 5, 3};

    int target = 3;
    int ans = count(arr.begin(), arr.end(), target);
    
    cout << ans;
    
    return 0;
}