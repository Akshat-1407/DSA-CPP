#include <iostream>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            // Avoid printing the square root twice
            if (i != n / i)
                cout << n / i << " ";
        }
    }
}

int main() {
    printDivisors(36);
}