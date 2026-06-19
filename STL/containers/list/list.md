# Member Functions:

- `begin()`: Returns an iterator pointing to the first element in the list.
- `end()`: Returns an iterator pointing to the past-the-end element in the list.
- `size()`: Returns the number of elements in the list.
- `empty()`: Checks if the list is empty (i.e., whether its size is 0).
- `front()`: Accesses the first element in the list.
- `back()`: Accesses the last element in the list.
- `push_back(const T& value)`: Adds an element to the end of the list.
- `pop_back()`: Removes the last element from the list.
- `insert(iterator position, const T& value)`: Inserts a new element before the specified position in the list.
- `erase(iterator position)` or `erase(iterator first, iterator last)`: Removes one or more elements from the list starting at the specified position.
- `clear()`: Removes all elements from the list, which are destroyed, and leaves it with a size of 0.
- `swap(list& x)`: Swaps the contents of the list with those of another list of the same type, including their sizes.
- `pop_front()`: Removes the first element from the list.
- `push_front(const T& value)`: Adds an element to the beginning of the list.
- `remove(const T& value)`: Removes all elements from the list that are equal to the specified value.