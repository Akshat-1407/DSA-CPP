#include <iostream>
using namespace std;

double binexp(double x, long long n) {
    double ans = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * x;
            n = n - 1;
        } else {
            x = x * x;
            n = n / 2;
        }
    }

    return ans;
}

double binExp(double x, long long n) {
    double ans = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * x;
        }
        n = n / 2;
        x = x * x;
    }

    return ans;
}

double BinExp(double x, long long n) {
    if (n == 0) {
        return 1;
    }
    else {
        double a = BinExp(x, n/2);
        if (n % 2 == 0) {
            return a * a; 
        }
        else {
            return a * a * x;
        }
    }
    return 0;
}

int main() {
    long long x, n;
    cin >> x >> n;

    cout << binExp(x, n) << endl;

    return 0;
}