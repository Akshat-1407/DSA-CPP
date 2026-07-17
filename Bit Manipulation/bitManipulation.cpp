#include <iostream>
#include <algorithm>

using namespace std;

// swap two numbers
void swapTwoNumbers(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// check if the ith bit is set or not, using left shift
bool checkBitSetLeft(int n, int i) {
    if(n & (1 << i) != 0)
        return true;
    else 
        return false;
}

// check if the ith bit is set or not, using right shift
bool checkBitSetRight(int n, int i) {
    if((n >> i) & 1 == 0)
        return true;
    else 
        return false;
}

// set the ith bit
int setBit(int n, int i) {
    return n | (1 << i);
}

// clear the ith bit
int clearBit(int n, int i) {
    return n & ~(1 << i);
}

// toggle the ith bit
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

// remove the last(rightmost) set bit
int removeLastSetBit(int n) {
    return n & n-1;
}

// check if no is a power if 2
bool powOfTwo(int n) {
    if (n <= 0) 
        return false;

    if((n & n-1) == 0)
        return true;
    else 
        return false;
}

// count number of set bits
int countSetBits1(int n) {
    int cnt = 0;

    while(n != 0) {
        n = n & n-1;
        cnt++;
    }
    return cnt;
}

// count the number of set bits
int countSetBits2(int n) {
    int count = 0;

    while(n > 0) {
        if(n % 2 == 1) count++; 
        // count += n & 1;
        n = n / 2; 
        // n = n >> 1;
    }

    return count;
} 

// check if the number is even or not using Bitwise AND operator
bool isEven1(int n) {  
    if ((n & 1) == 0)
        return true;
    else
        return false;
}
// check if the number is even or not using Bitwise OR operator
bool isEven2(int n) {
    if ((n | 1) > n)
        return true;
    else
        return false;
}
// check if the number is even or not using Bitwise XOR operator
bool isEven3(int n) {
    if ((n ^ 1) == (n + 1))
        return true;
    else
        return false;
}


int main() {

    int n = 16;
    // cout << countSetBits2(n);
    // cout << setBit(n, 0);
    cout << isEven1(9);

    return 0;
}