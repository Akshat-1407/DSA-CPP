#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    
    // Count reverse pairs BEFORE merging
    int reversePairCount = 0;

    int right = mid + 1;
    for (int left = low; left <= mid; left++) {
        while (right <= high && (long long)arr[left] > 2 * arr[right]) {
            right++;
        }
        reversePairCount += right - (mid + 1);
    }
    
    // Merge step
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
            // invCount += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + low] = temp[idx];
    }
    
    return reversePairCount;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    int leftCount = mergeSort(arr, low, mid);
    int rightCount = mergeSort(arr, mid + 1, high);
    int mergeCount = merge(arr, low, mid, high);

    return leftCount + rightCount + mergeCount;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}


int main() {
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    int n = arr.size();

    int ans = reversePairs(arr);
    cout << "Reverse Pairs: " << ans;
    
    return 0;
}