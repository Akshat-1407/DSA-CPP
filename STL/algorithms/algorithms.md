# Iterators and Iterating Algorithms:

* **`std::for_each`**: Applies a function to each element in a range. 
* **`std::find`**: Searches for a specific element in a range and if found return the iterator of that element else return the last iterator.
* **`std::find_if`**: Searches for the first element that satisfies a given predicate.
* **`std::count`**: Counts the occurrences of a value in a range.
* **`std::count_if`**: Counts the elements that satisfy a given predicate.
* **`std::sort`**: Sorts the elements in a range in ascending order.
* **`std::reverse`**: Reverses the order of elements in a range.
* **`std::rotate`**: Rotates elements in a range.
* **`std::unique`**: Removes duplicate elements from a sorted range.
* **`std::partition`**: Divides elements in a range into two groups based on a predicate.


# Numeric Algorithms:

* **`std::accumulate`**: Computes the sum of elements in a range.
* **`std::inner_product`**: Computes the inner product of two ranges.
* **`std::partial_sum`**: Computes the partial sums of a range.
* **`std::iota`**: Fills a range with incrementing values.


# Searching and Finding Algorithms:

* **`std::binary_search`**: Checks if a value exists in a sorted range.
* **`std::lower_bound`**: Finds the first element greater or equal to a value in a sorted range.
* **`std::upper_bound`**: Finds the first element greater than a value in a sorted range.

* **`std::equal_range`**: performs a binary search and returns a `std::pair` containing two iterators:
    * **`first`**: The result of `std::lower_bound` (the first element that is not less than the value).
    * **`second`**: The result of `std::upper_bound` (the first element greater than the value).


# Min and Max Algorithms:

* **`std::min`**: Returns the smaller of two values.
* **`std::max`**: Returns the larger of two values.
* **`std::min_element`**: Finds the smallest element in a range.
* **`std::max_element`**: Finds the largest element in a range.


# Heap Algorithms:

* **`std::make_heap`**: Converts a range into a max-heap.
* **`std::push_heap`**: Inserts an element into a max-heap.
* **`std::pop_heap`**: Removes the largest element from a max-heap.
* **`std::sort_heap`**: Sorts a range that represents a max-heap.


# Set Algorithms:

* **`std::set_union`**: Computes the union of two sorted ranges.
* **`std::set_intersection`**: Computes the intersection of two sorted ranges.
* **`std::set_difference`**: Computes the difference between two sorted ranges.
* **`std::set_symmetric_difference`**: Computes the symmetric difference of two sorted ranges.