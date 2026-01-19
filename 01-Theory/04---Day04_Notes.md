TOPIC[QUICK SORT (PARTITION , RANDOM PARTITION ,HOARE PARTITION)]
1----------------------------------------------------------------
The n \log n Boundary: Use the Master Method to solve T(n) = T(n/10) + T(9n/10) + n. (This proves that even an unbalanced 1:9 split is still O(n log n)).
---
Use the Master Method to solve T(n)=T(n/10)+T(9n/10)+n. This shows that even an unbalanced 1:9 split still results in O(n\log n).
We have:
T(n)=T(n/10)+T(9n/10)+n
Using the recursion tree method, we observe that the work at each level is approximately n. After the recursion depth reaches about \log n, each level continues to contribute at most n work. Therefore, the total number of levels is bounded by \log n.
Thus, the overall time complexity is:
T(n)=O(n\log n)
independent of how the division is split.


2--------------------------------------------------------------------------
In-Place vs Stable: Why is the standard partitioning unstable? Give an example of two identical elements that swap positions during a Lomuto partition.
---
as relative position can change so becomes unstable though it is in-place .
eg. [(3, 'A'), (3, 'B'), (2, 'C')]

3----------------------------------------------------------------------------
Stack Space Math: If we don't use tail-recursion optimization, what is the maximum stack depth of QuickSort on an already sorted array of size n?
---
In QuickSort, the stack depth is determined by the sequence of recursive calls rather than the partitioning itself. If tail‑recursion optimization is not applied and the pivot is always chosen as the first or last element, then on an already sorted array each partition produces one empty subarray and one subarray of size n-1. This leads to a chain of recursive calls of size n,n-1,n-2,\dots ,1, with each call waiting for the next to finish. As a result, the recursion stack grows linearly with the input size, and the maximum stack depth in this worst case is O(n).
