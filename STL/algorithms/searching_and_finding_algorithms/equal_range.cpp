#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> data = {1, 2, 4, 4, 4, 5, 7};
    int target = 4;

    auto bounds = equal_range(data.begin(), data.end(), target);

    if (bounds.first != bounds.second) {
        cout << "Found " << target << " in the range!\n";
        
        auto count = distance(bounds.first, bounds.second);
        cout << target << " appears " << count << " times.\n";
        
        cout << "Elements: ";
        for (auto it = bounds.first; it != bounds.second; ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    } else {
        cout << target << " was not found.\n";
    }

    return 0;
}