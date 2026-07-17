#include <iostream>
#include <algorithm>

using namespace std;

int binaryToDecimal(string s) {
    int ans = 0;

    int powOfTwo = 1;    
    for(int i = s.length()-1; i >= 0; i--) {
        if(s[i] == '1') {
            ans += powOfTwo;
        }
        powOfTwo = powOfTwo * 2;
    }

    return ans;
}

int main() {

    string s = "111";
    cout << binaryToDecimal(s);

    return 0;
}