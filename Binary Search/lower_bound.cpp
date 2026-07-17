#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int>& nums, int n, int target) {
    int left = 0;
    int right = n - 1;
    int lowerBound = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            lowerBound = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1; 
        }
    }  
    return lowerBound;     
}

