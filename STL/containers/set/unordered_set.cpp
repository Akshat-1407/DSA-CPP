#include <iostream>
#include <set> // all operations in log n time
#include <unordered_set>  // all operations in constant time

using namespace std;

int main() {
    
    unordered_set<int> set;

    // Insertion 
    set.insert(10);
    set.insert(15);
    set.insert(25);
    set.insert(20);
    

    // Iterator
    unordered_set<int>:: iterator it = set.begin();

    while(it != set.end()) {
        cout << *it << endl;
        it++; 
    }

    // find
    auto ite = set.find(10);
    cout << endl;
    if (ite != set.end()) {
        cout << *ite << "\n\n"; // Safe to print if found
    } else {
        cout << "Element not found\n\n";
    }

    // count
    cout << "Count: " << set.count(15) << endl;

    // clear
    set.clear();
    if(set.size() == 0) cout << "Empty";

    return 0;
}