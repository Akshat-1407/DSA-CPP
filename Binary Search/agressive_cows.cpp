#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int canPlaceCows(vector<int> &arr, int cows, int minDist) {
    int n = arr.size();
    
    int cowsPlaced = 1;
    int lastCow = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] - lastCow >= minDist) {
            cowsPlaced++;
            lastCow = arr[i];
        }
        
        if(cowsPlaced >= cows) {
            return true;
        }
    }
    
    return false;

}

int aggressiveCows(vector<int> &arr, int k) {
    
    sort(arr.begin(), arr.end());
    
    int ans = 0;
    int low = 1;
    int high = arr[arr.size() - 1] - arr[0];
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(canPlaceCows(arr, k, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;
}
