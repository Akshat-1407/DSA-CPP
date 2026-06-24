#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Reads each space-separated integer seamlessly
    }
    for(int e: arr) {
        cout << "Element: " << e;
    }
    // Your logic here...
    return 0;
}