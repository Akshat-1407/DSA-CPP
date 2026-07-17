#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isValid(vector<int> &arr, int k, int maxAllowedPages) {
    int n = arr.size();
    
    int student = 1;
    int pages = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > maxAllowedPages) {
            return false;
        }
        else if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } 
        else {
            student++;
            pages = arr[i];
        }
    }
    
    if(student > k) 
        return false;
    else
        return true;
}



int findPages(vector<int> &arr, int k) {
    if(k > arr.size()) return -1;
    
    int ans = -1;
    
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(isValid(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return ans;
}