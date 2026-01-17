TOPIC[COMPARISION DECISION TREE AND BINARY SEARCH]
1-----------------------------------------
The Lower Bound: Explain in your own words why we can't sort faster than nlogn using only comparisons between two elements.
----
In any comparison-based sorting algorithm, such as merge sort or quicksort, we are given n unique elements to sort. There are n! possible permutations of these elements.
Each comparison-based sorting algorithm can be represented as a decision tree, where each internal node corresponds to a comparison between two elements, and each leaf corresponds to one possible sorted permutation. Since the algorithm must be able to produce all possible permutations, the decision tree must have at least n! leaves.
In a binary decision tree of height h, the maximum number of leaves is 2^h. Therefore, we must have:
total number of leafs as l .then now,
n!<=l<=2^h
log(n!)<=h
nlog(n)<=h
so, h=Big Omega(nlog(n))
Thus, the height of the decision tree—and therefore the worst-case number of comparisons—has a lower bound of Big Omega(nlog(n)). This shows why no comparison-based sorting algorithm can be faster than n\log n in the worst case.


2-------------------------------------------
Iterative vs Recursive: Compare the Space Complexity of both for Binary Search. Explain why the iterative version is "Hardware-Safer."
---
Iterative binary search uses variables such as low, high, and mid inside a loop until the condition low > high is reached. The memory usage here is constant because only these few variables are maintained throughout the process. Therefore, the space complexity of the iterative version is O(1).
where as recursive binary search repeatedly calls itself, and each call creates a new stack frame that stores parameters like low, high, and mid along with the return address. This consumes stack memory, and in the worst case, the recursion continues until the search space is reduced to a single element. Since the array size is halved at each step, the depth of recursion is log n, which means the space complexity of the recursive version is O(log n). 
The iterative version is considered “hardware-safer” because it does not rely on stack memory, avoiding the risk of stack overflow. It guarantees constant memory usage regardless of input size, while the recursive version depends on stack capacity, which is limited by hardware.


3---------------------------------------------
Logarithmic Power: If you have an array of the size of the entire human population (approx 8 billion), how many steps maximum does Binary Search take to find a name?
---
max till when subproblem has only one element left that is n/(2^k)=1 so k or steps =logn base of 2.
steps=log(8 billion) =3+29.9= 33 steps in approx as steps are integer.