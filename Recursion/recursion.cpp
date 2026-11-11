#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else   
        return gcd(b, a % b);
}

int fact(int n) {
    if (n == 0)
        return 1;
    else 
        return n * fact(n-1);
}

int arrSum(int arr[], int n) { // Here n is the last index
    if (n <= 0) 
        return arr[0];
    else 
        return arr[n] + arrSum(arr, n-1);
}

// palidrome check
bool isPalindrome(int i, string s, int n) {
    if(i >= n/2)
        return true;
    
    if(s[i] != s[n-i-1])
        return false;

    return isPalindrome(i+1, s, n);
}

// array reverse uisng two pointer recursion
void arrRev(vector<int> arr, int l, int r) {
    if(l >= r) 
        return;
    
    swap(arr[l], arr[r]);
    arrRev(arr, l+1, r-1);
}

// arrar reverse using single pointer recursion
void ArrRev(int i, vector<int> arr, int n) {
    if(i >= n/2) 
        return;
    
    swap(arr[i], arr[n-i-1]);
    ArrRev(i+1, arr, n);
}

// find digit sum
int digitSum(int n){
    if(n == 0)
        return 0;
    else
        return (n % 10) + digitSum(n / 10);
}

// Normal
int Pow(int a, int n) {
    if(n == 0)
        return 1;
    else    
        return a * Pow(a, n-1);
}

// Binary Exponentiation
int Pow_BinExp(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        int x = Pow_BinExp(a, n/2);
        if (n % 2 == 0) {
           return x * x; 
        }
        else {
            return a * x * x;
        }
    }
}

// O(2^n)
int fib(int n) {
    if (n <= 2) 
        return n-1;
    else 
        return fib(n-1) + fib(n-2);
}

// Optimized
int optimizedFib(int n) {
    int DAT[101] = {0};
    if (n <= 2) 
        return n-1;
    else 
        if (DAT[n] == 0 ) {
            DAT[n] = fib(n-1) + fib(n-2);
        }
        return DAT[n];
}

// counting for st to end
void counting(int st, int end) {
    if(st > end) 
        return;
    
    cout << st << " ";
    counting(st + 1, end);
}

// reverse counting from st to end
void revCounting(int st, int end) {
    if(st < end) 
        return;
    
    cout << st << " ";
    revCounting(st-1, end);
}

// counting using backtracking
void backtrackingCount(int i, int n) {
    
    if(i < 1) 
        return;
    
    backtrackingCount(i-1, n);
    cout << i << " ";
}

// reverse counting using backtracking
void revBacktrackingCount(int i, int n) {
    
    if(i > n)
         return;
    
    revBacktrackingCount(i+1, n);
    cout << i << " ";
}

// sum of first n numbers using functional recursion
int nsum(int n) {
    if(n == 0) 
        return 0;
    
    return n + nsum(n - 1);
}

// sum of first n numbers using parameterised recursion
void NSumParams(int i, int sum) {
    if(i == 0) {
        cout << sum << endl;
        return;
    }
    
    NSumParams(i - 1, sum + i);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << "GCD: " << gcd(60, 36) << endl;
    cout << "Fib: " << fib(5) << endl;
    cout << "Optimized Fib: " << optimizedFib(5) << endl;
    cout << "Power: " << Pow(2, 10) << endl;
    cout << "Power using Binary Exponentiaion: " << Pow_BinExp(2, 10) << endl;
    cout << "Factorial: " << fact(5) << endl;
    cout << "DigitSum: " << digitSum(123) << endl;
    cout << "Array Sum: " << arrSum(arr, 4) << endl;

	counting(1, 20);
	cout << endl;
	
	revCounting(20, 1);
    cout << endl;
    
    backtrackingCount(25, 25);
    cout << endl;
    
    revBacktrackingCount(1, 25);
    cout << endl;
    
    cout << nsum(10);
    cout << endl;
    
    NSumParams(20, 0);
    cout << endl;

    return 0;
}
