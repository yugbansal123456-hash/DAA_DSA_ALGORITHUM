TOPIC[BST]
1--------------------------------------------------------------------------------
Height Comparison: What is the height of a balanced tree with n nodes vs. a skewed tree? Use n=1024 as your example.
---
The height of a binary tree depends on whether it is balanced or skewed. In a balanced binary tree, the height grows logarithmically with the number of nodes. For example, with n=1024, the height is \log _21024=10. In contrast, a skewed tree—such as when nodes are inserted in sorted order—places all elements along one side, making the height equal to the number of nodes. Thus, for n=1024, the height is 1024. This shows that balanced trees are far more efficient, as their height increases slowly compared to skewed trees, which grow linearly and can degrade performance.


2---------------------------------------------------------------------------------
Successor Logic: In your own words, why do we use the minimum of the right subtree as the successor when a node has two children?
---
When a node in a binary search tree has two children, we use the minimum value from its right subtree as the successor. This is because, in an inorder traversal, the next element after the node to be deleted is precisely that minimum. By replacing the node with this successor, we preserve the sorted order of the traversal and maintain the binary search property. Choosing the minimum of the right subtree ensures that all values in the left subtree remain smaller and all values in the right subtree remain larger, thereby keeping the structure valid.

3---------------------------------------------------------------------------------
Inorder Property: Prove (informally) why an Inorder traversal of a BST always results in a sorted array.
---
An inorder traversal of a binary search tree always produces a sorted sequence because of the BST property itself. By definition, every node’s left subtree contains values less than or equal to the node’s key, and every node’s right subtree contains values greater than or equal to the node’s key. Inorder traversal visits nodes in the order: left subtree → root → right subtree, recursively. This means we first collect all smaller values, then the current node, and finally all larger values. Since this rule is applied consistently at every node, the resulting sequence respects the BST ordering at each step, and the final output is a sorted array of all the keys


4-------------------------------------------------------------------------------------
Understand the Skewed Tree problem. In your notes, explain why a BST can accidentally become O(n) if the input is already sorted. This is why we need balancing (which we'll hit in the future).
---
A binary search tree can accidentally degrade to O(n) performance if the input is already sorted. This happens because each new element is always inserted as the right child (or left child, depending on order), creating a chain rather than a balanced structure. Instead of having a logarithmic height like a balanced tree, the height becomes equal to the number of nodes. As a result, operations such as search, insert, and delete, which ideally run in O(\log n), now take O(n) time in the worst case. In effect, the BST degenerates into a linked list when given sorted input. This problem highlights why balancing techniques (like AVL trees or Red-Black trees) are necessary: they restructure the tree to maintain logarithmic height and prevent performance collapse.