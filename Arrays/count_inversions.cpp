#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    
    int invCount = 0;
    
    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
            invCount += mid - i + 1;
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
        arr[idx+low] = temp[idx];
    }
    
    return invCount;
}  


int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    int leftInvCount = mergeSort(arr, low, mid);
    int rightInvCount = mergeSort(arr, mid + 1, high);
    int invCount = merge(arr, low, mid, high);

    return leftInvCount + rightInvCount + invCount;
}


int inversionCount(vector<int> &arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}


int main() {
    vector<int> arr = {6, 3, 5, 2, 7};
    int n = arr.size();

    int ans = inversionCount(arr);
    cout << "Total Inversion Counts: " << ans;
    
    return 0;
}




