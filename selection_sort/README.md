# Selection Sort
As the name implies, it selects the smallest value in remaining unordered section of the array.
Therefore, it'll do n-1 comparisons.

i.e.

Array: [|7, 4, 2, 6]

1. 2 is the min in the unsorted section: swap 7 and 2

[2| 4, 7, 6]

2. 4 is the min in the unsorted section: no swap

[2, 4| 7, 6]

3. 6 is the min: swap 7 and 6

[2,4,6,7]

Completed (stop after n-1 comparisons)




