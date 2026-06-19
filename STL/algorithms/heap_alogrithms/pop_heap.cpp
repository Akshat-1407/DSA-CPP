#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {

    vector<int> arr = {22, 11, 55, 66, 77};

    make_heap(arr.begin(), arr.end());

    for(int a: arr) {
        cout << a << " " ;
    } cout << endl;


    //deletion
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();

    for(int a: arr) {
        cout << a << " ";
    } cout << endl;

    return 0;
}