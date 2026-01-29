TOPIC[LINEAR DATA]
1---------------------------------------------------------------------------
Sentinel Nodes: Explain how using a "Dummy Head" node simplifies the code for inserting/deleting in a linked list.
---
Using a dummy head node, also called a sentinel node, simplifies insertion and deletion operations in a linked list because it provides a consistent starting point. Instead of having to write special cases for when changes occur at the very beginning of the list, the dummy head ensures that the actual list always begins at dummy->next. This means that whether we insert or delete at the front or in the middle, the logic remains uniform, avoiding conditional checks for the head pointer. In the end, the dummy head is mainly a convenience: it makes the code cleaner, easier to understand, and less error-prone.


2---------------------------------------------------------------------------
Queue Overflow: In a circular array-based queue of size $N$, why can we only store N-1 elements?
---
In a circular array-based queue of size N, we can only store N-1 elements because of the way the empty and full conditions are defined. The queue is considered empty when the head and tail pointers are equal. At the same time, the tail pointer indicates the position where the next element will be enqueued. If we allowed all N slots to be filled, then the condition for a full queue would also make head equal to tail, which is indistinguishable from the empty case. To avoid this ambiguity, one slot is always left unused. As a result, the maximum number of storable elements is N-1, ensuring that the queue can clearly differentiate between being full and being empty.


3----------------------------------------------------------------------------
Space Trade-off: If you have 1GB of RAM, how many nodes can you store in a Doubly Linked List of int (4 bytes) vs. a Singly Linked List of int?
---
If you have 1 GB of RAM, the number of nodes you can store depends on whether you are using a singly linked list or a doubly linked list, since the node size differs. On a 64-bit system, an int takes 4 bytes and each pointer takes 8 bytes, with alignment padding applied. A singly linked list node consists of the integer data and one pointer, giving a raw size of 12 bytes, which aligns to 16 bytes. A doubly linked list node consists of the integer data and two pointers, giving a raw size of 20 bytes, which aligns to 24 bytes. Since 1 GB equals 2^{30} bytes
1GB=1024MB=2^20KB=2^30BYTES=1,07,37,41,824 bytes
Doubly link list(4+8+8=20 ->24) =4,47,39,242
singly link list(4+8=12 ->16)=6,71,08,864


4--------------------------------------------------------------------------------
Understand Pointer Overhead. In your notes, calculate the memory difference between a std::vector<int> and a std::list<int> for 1 million integers. (Hint: In a 64-bit system, every list node has two 8-byte pointers plus the 4-byte integer).
---
To understand pointer overhead, consider storing one million integers in a std::vector<int> versus a std::list<int> on a 64‑bit system. A vector stores its elements in a contiguous array, so each integer requires only 4 bytes, with minimal overhead beyond the array itself. Thus, one million integers in a vector consume about 1,000,000\times 4=4,000,000 bytes, or roughly 4 MB. In contrast, a doubly linked list node must store not only the integer but also two pointers (each 8 bytes). That gives 4+8+8=20 bytes per node, which aligns to 24 bytes due to padding. Therefore, one million integers in a list consume about 1,000,000\times 24=24,000,000 bytes, or roughly 24 MB. The difference is striking: the list uses about 20 MB more memory than the vector for the same number of integers, showing how pointer overhead in linked structures can significantly increase memory usage compared to contiguous arrays.
