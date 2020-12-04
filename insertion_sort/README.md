# Insertion Sort

As the name implies, it'll insert a single element at a time to the ordered 
subset of the array.

**Complexity:**

1. We know that the sorting algorithm has to compare n elements
    * makes n-1 comparisons
2. An element needs to move at most n-1 positions
So it's likely the worst time complexity is O(n^2)

**Example of Worst Case:**

[5, 4, 3, 2, 1]

An array sorted from greatest to least

0. [5|, 4, 3, 2, 1]
1. [4, 5|, 3, 2, 1] +1 movement
2. [4, 3, 5|, 2, 1] +2 movement
   [3, 4, 5|, 2, 1]
3. [3, 4, 2, 5|, 1] +3 movement
   [3, 2, 4, 5|, 1]
   [2, 3, 4, 5|, 1]
4. [2, 3, 4, 1, 5|] +4 movement
   [2, 3, 1, 4, 5|]
   [2, 1, 3, 4, 5|]
   [1, 2, 3, 4, 5|]

For an array of length 5:
* Swapped: 1 + 2 + 3 + 4 = (n^2-n)/2
Therefore the worst case time complexity is O(n^2).

**Example of Best Case:**

[1, 2, 3, 4, 5]
* since the array is sorted, there are 0 swaps
* there will be n-1 comparisons
Therefore, best time complexity is O(n)