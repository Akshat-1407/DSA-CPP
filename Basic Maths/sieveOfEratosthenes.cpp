#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieveOfEratosthenes(int n) {
    // Fast exit for edge cases
    if (n <= 1) return;

    // Vector initialized to true; std::vector<bool> uses 1 bit per element
    vector<bool> isPrime(n + 1, true);
    
    isPrime[0] = isPrime[1] = false;

    // Outer loop only goes up to sqrt(n)
    int limit = sqrt(n);
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            // Start crossing out at i * i
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Output the results
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n = 100;
    cout << "Primes up to " << n << ":\n";
    sieveOfEratosthenes(n);
    
    return 0;
}