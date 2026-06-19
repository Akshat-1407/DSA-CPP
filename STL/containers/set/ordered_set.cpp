#include <iostream>
#include <set> // all operations in log n time
#include <unordered_set>  // all operations in constant time

using namespace std;

int main() {
    
    set<int> st;

    // Insertion 
    st.insert(10);
    st.insert(15);
    st.insert(25);
    st.insert(20);
    

    // Iterator
    set<int>:: iterator it = st.begin();

    while(it != st.end()) {
        cout << *it << endl;
        it++; 
    }

    // find
    auto ite = st.find(10);
    cout << endl;
    if (ite != st.end()) {
        cout << *ite << "\n\n"; // Safe to print if found
    } else {
        cout << "Element not found\n\n";
    }

    
    // count
    cout << "Count: " << st.count(15) << endl;

    // clear
    st.clear();
    if(st.size() == 0) cout << "Empty";

    return 0;
}