#include <iostream>
#include <algorithm>

using namespace std;

string decimalToBinary(int n) {
    string ans = "";

    while(n > 0) {
        if(n % 2 == 1)
            ans += '1';
        else 
            ans += '0';

        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    int n = 18;
    cout << decimalToBinary(n);

    return 0;
}