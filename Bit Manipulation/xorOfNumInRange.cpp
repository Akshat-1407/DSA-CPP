#include <iostream>

using namespace std;

// Find the XOR of numbers in a given range
int xorUpto(int n) {
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int xorRange(int L, int R) {
    return xorUpto(R) ^ xorUpto(L - 1);
}