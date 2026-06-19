#include <iostream>
#include <map> // all operations in log n time
#include <unordered_map>  // all operations in constant time

using namespace std;

int main() {
    
    unordered_map<string, string> table;

    // Insertion 
    table["IN"] = "India";

    table.insert(make_pair("US", "United States"));

    pair<string, string> p;
    p.first = "EN";
    p.second = "England";
    table.insert(p);

    // Finding the Value of a particular key
    cout << table.at("IN") << endl; // Gives error if key is not present
    

    // Iterator
    unordered_map<string, string>:: iterator it = table.begin();

    while(it != table.end()) {
        pair<string, string> p = *it;
        cout << p.first << ": " << p.second << endl;
        it++; 
    }

    // find
    if(table.find("US") != table.end()) {
        pair<string, string> p = *table.find("US");
        cout << "Key Found" << " -> " << p.first << ": " << p.second << endl;        
    }
    else {
        cout << "Key Not Found" << endl;
    }

    // count
    cout << "Count of EN: " << table.count("EN") << endl;

    // clear
    table.clear();
    if(table.size() == 0) cout << "Empty";

    return 0;
}