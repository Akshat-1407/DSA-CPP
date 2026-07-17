#include <iostream>
#include <cmath>
using namespace std;

/* An Armstrong number is a number that is equal to the sum of its digits, 
where each digit is raised to the power of the total number of digits. */

bool isArmstrong(int n) {
    int original = n;
    int digits = 0;

    int temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    int sum = 0;
    temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cin >> n;

    if (isArmstrong(n))
        cout << "Armstrong";
    else
        cout << "Not Armstrong";

    return 0;
}