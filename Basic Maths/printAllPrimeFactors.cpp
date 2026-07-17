#include <iostream>
using namespace std;

// Print each prime factor only once (distinct prime factors)
void primeFactors(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        cout << n;
}

int main() {
    primeFactors(84);
}