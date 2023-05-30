# Binary-Search-Tree
A binary search tree (BST) is a data structure that organizes elements in a hierarchical manner. It provides efficient insertion, deletion, and search operations.
The structure of a binary search tree ensures that the values in the left subtree of a node are less than the node's value, and the values in the right subtree are 
greater than the node's value.

Here's a brief introduction to binary search trees:

1. Node Structure: Each node in a binary search tree contains a value and references to its left and right child nodes.

2. Tree Property: The binary search tree property states that for every node, the values in its left subtree are less than its value, and the values in its right subtree
    are greater than its value.

3. Insertion: To insert a new element into a binary search tree, compare the value with the current node. If the value is less than the node, move to the left child and repeat
   the process. If the value is greater than the node, move to the right child and repeat the process. Continue until reaching an empty child position, then create a new node 
   with the given value and attach it as the appropriate child.

4. Deletion: Deleting a node from a binary search tree requires reorganizing the tree to maintain the binary search tree property. There are three possible cases to consider:
   a node with no children, a node with one child, and a node with two children. The deletion process involves finding the appropriate node to delete, adjusting the references 
   of the parent and child nodes, and handling the different cases accordingly.

5. Searching: To search for a specific value in a binary search tree, start at the root node and compare the value with the current node. If the value matches, the search is
   successful. If the value is less than the current node, move to the left child and repeat the process. If the value is greater than the current node, move to the right child 
   and repeat the process. Continue until finding the desired value or reaching an empty child position.

6. Traversals: Binary search trees support different types of tree traversals, such as in-order, pre-order, and post-order. These traversals allow you to visit all the nodes
   in a specific order.
