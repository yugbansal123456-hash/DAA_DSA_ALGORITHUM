TOPIC[Divide and Conqure ,Merge Sort ,Solving Recurrence equation(Master Methord,visual methord)]
1-------------------------------------------------------
Merge Complexity: Prove why merging two arrays of total size n takes O(n) time.
---
Let nums[p:m] contain m-p+1=k elements, and nums[q:r] contain r-q+1=t elements, with t+k=n as the total number of elements. To merge them into a[p:n], we first use a while loop that compares elements from both lists until one of the lists becomes empty. This requires at most n-1 comparisons. After that, we copy the remaining elements from whichever list is not yet exhausted. In this way, every element is visited exactly once, so the merge step takes O(n) time.


2------------------------------------------------------
Stable vs. Unstable: Research if your Merge Sort is "Stable" (does it preserve the relative order of equal elements?). Why is stability important for database sorting?
---
Merge Sort is a stable algorithm because it preserves the relative order of equal elements during merging. Stability is especially important in database sorting since it guarantees that when records share the same key, their original order (often determined by another attribute) is maintained. This ensures reliable multi-key sorting, consistent query results, and predictable behavior in applications where data integrity matters.As well as -  cache hits, the more precise reason is that stability avoids unnecessary reordering, which helps maintain predictable memory access patterns and reduces overhead in repeated queries


3--------------------------------------------------------
In-Place Reality: Why is it so difficult to make Merge Sort O(1)space?
---
In Merge Sort, the dividing step is not an issue since it only requires index manipulation and therefore uses O(1) extra space. The challenge arises in the merging step: elements must be copied from the original array into a temporary array, which requires O(n) space proportional to the number of elements being merged. Without this copying, refilling the original array directly would cause overwriting errors and incorrect ordering. Thus, achieving O(1) space for Merge Sort is difficult, except under specific conditions or with specialized in-place merging techniques(like already ordered subarrays).