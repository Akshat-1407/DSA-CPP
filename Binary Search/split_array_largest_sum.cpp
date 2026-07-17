#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int countPartitions(vector<int>& nums, int k, int maxSubSum) {
    int n = nums.size();

    int partition = 1;
    int currSubSum = 0;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] > maxSubSum) {
            return false;
        }
        else if(currSubSum + nums[i] <= maxSubSum) {
            currSubSum += nums[i];
        } 
        else {
            partition++;
            currSubSum = nums[i];
        }
    }
    
    return partition < k;
}

int splitArray(vector<int>& nums, int k) {
    int ans = -1;
    
    int low = *min_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(countPartitions(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}