#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, string> p;

    p.first = 10;
    p.second = "Hello";

    cout << p.first << " " << p.second << endl;

    pair<int, string> q = make_pair(20, "World");

    p.swap(q);

    cout << p.first << " " << p.second << endl;

    return 0;
}