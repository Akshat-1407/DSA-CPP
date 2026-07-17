#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;

    n = abs(n);
    int count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countDigits(n);

    return 0;
}