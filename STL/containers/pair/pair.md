# std::pair Member Functions

- `pair()`: Default constructor. Constructs a pair with default-initialized values.
- `pair(const T1& x, const T2& y)`: Constructs a pair with the specified values.
- `pair(const pair& other)`: Copy constructor. Constructs a pair by copying another pair.
- `pair(pair&& other)`: Move constructor. Constructs a pair by moving another pair.
- `operator=(const pair& other)`: Copy assignment operator.
- `operator=(pair&& other)`: Move assignment operator.
- `swap(pair& p)`: Swaps the contents of the pair with another pair.

# Data Members

- `first`: Stores the first value in the pair.
- `second`: Stores the second value in the pair.

# Helper Function

- `std::make_pair(T1 x, T2 y)`: Creates and returns a `std::pair` object with automatically deduced types.

# Comparison Operators

- `operator ==`: Checks if two pairs are equal.
- `operator !=`: Checks if two pairs are not equal.
- `operator <`: Checks if one pair is lexicographically less than another.
- `operator <=`: Checks if one pair is lexicographically less than or equal to another.
- `operator >`: Checks if one pair is lexicographically greater than another.
- `operator >=`: Checks if one pair is lexicographically greater than or equal to another.

