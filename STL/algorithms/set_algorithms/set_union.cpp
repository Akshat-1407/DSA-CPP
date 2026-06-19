#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
            
    vector<int> first = {1, 2, 3, 4};
            
    vector<int> second = {3, 4, 5, 6};

    vector<int> result;

    set_union(first.begin(), first.end(), second.begin(), second.end(),inserter(result, result.begin()));

    for(int a: result) {
        cout << a << " ";
    }

    return 0;
}