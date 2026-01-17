TOPIC[TIME AND SPACE COMPLEXITIES, RATE OF GROWTH]
1------------------------------------------------------
Formal Definitions: Explain what the constants c and n0 represent in the formal definition of Big O-notation 
---
f(n)=O(g(n)) for n>=n0
which means
f(n)<=cg(n) 
here, n0 represents the point from which the inequality must hold for all larger values of n. The constant c>0 is a scaling factor such that cg(n) is always greater than or equal to f(n) once n>=n0. Hence, cg(n) becomes an upper bound for f(n) beyond this threshold, which is why we say g(n) asymptotically bounds   f(n) from above.


2-------------------------------------------------------
Memory Math: If an int is 4 bytes and arr[0] is at address 0x100, calculate the exact hex address of arr[12].
---
let take a[i] address as a_i now let size of element a[i] be s .
now find address of a[j] which is a_j:
a_j=a_i+s*(j-1)
so for this ,s=4,a_i=0X100,j-i=12;
a_i(0-15)(hex)+48(0-9)(dec)
16*3=48(030)
now add--->0X100+0x030
so address of a[12] is 0X130


3-----------------------------------------------------------
The Constant Myth: Why is O(2n) mathematically identical to O(n) in the long run?
---
if given time complexity f(n)=cn +k,c>0 and real k. or any thing else  In these    f(n) we first look for dominant terms which monotonic increase is highest .then we ignore all terms other than dominant term as well as we drop the constant of the dominant term as when n is very large its constant becomes meaningless in end only the term with highest groth rate is considered even if we take c very large it is meaningless O(1000000n)=O(33n)=O(n).


4-------------------------------------------------------------
Hardware Efficiency: Explain why a "Cache Miss" occurs more often in a structure that is not contiguous (like a Linked List) compared to an Array.
---
Cache is a small, fast memory layer near the CPU that allows quick access to nearby elements within a cache line. In arrays, memory is allocated contiguously, so once an element is accessed, a block of neighboring elements is also loaded into the cache line. This enables efficient access and is known as spatial locality. In contrast, linked lists store each node at different, non‑contiguous memory locations. When a cache line is loaded, it may not contain the next node, making the cache less useful. Therefore, linked lists are less efficient and less cache‑friendly, as they do not benefit from spatial locality.