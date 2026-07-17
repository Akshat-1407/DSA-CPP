# Sorting Algorithms Comparison

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable | Description |
|-----------|-----------|--------------|------------|-------|--------|-------------|
| Bubble Sort | **O(N)** | **O(N²)** | **O(N²)** | **O(1)** | ✅ Yes | Repeatedly swaps adjacent elements if they are in the wrong order. |
| Insertion Sort | **O(N)** | **O(N²)** | **O(N²)** | **O(1)** | ✅ Yes | Builds the final sorted list one item at a time by inserting elements into their correct position. |
| Selection Sort | **O(N²)** | **O(N²)** | **O(N²)** | **O(1)** | ❌ No | Repeatedly finds the minimum element and puts it at the beginning. |
| Merge Sort | **O(N log N)** | **O(N log N)** | **O(N log N)** | **O(N)** | ✅ Yes | Divide-and-conquer: recursively splits the array into halves, sorts them, and merges them back. |
| Quicksort | **O(N log N)** | **O(N log N)** | **O(N²)** | **O(log N)** | ❌ No | Divide-and-conquer: partitions the array around a pivot element. |
| Heap Sort | **O(N log N)** | **O(N log N)** | **O(N log N)** | **O(1)** | ❌ No | Uses a binary heap data structure to repeatedly find and extract the maximum/minimum element. |
| Counting Sort | **O(N + K)** | **O(N + K)** | **O(N + K)** | **O(K)** | ✅ Yes | Non-comparison: counts the occurrences of distinct elements to position them directly. |
| Radix Sort | **O(N × K)** | **O(N × K)** | **O(N × K)** | **O(N + K)** | ✅ Yes | Non-comparison: sorts elements digit by digit or character by character. |

---

# Other Notable Sorting Algorithms

- **Shellsort:** An extension of Insertion Sort that allows the exchange of items far apart.
- **Bucket Sort:** Distributes elements into arrays of *buckets* and then sorts each bucket individually.
- **Timsort:** A hybrid sorting algorithm derived from Merge Sort and Insertion Sort; used as the standard sorting algorithm in Python and Java.
- **IntroSort:** A hybrid of Quicksort and Heapsort, used in many C++ Standard Template Libraries (STL) to avoid worst-case scenarios.
- **Bogo Sort:** A highly inefficient, purely theoretical sorting algorithm based on the trial-and-error method.