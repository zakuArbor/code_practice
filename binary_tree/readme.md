# Binary Tree

## Implementations:
* Preorder Traversal
* Inorder Traversal
* Postorder Traversal
* Binary Search Tree

## To Implement
* Add node to BST
* Delete node in BST

## Testing
Basic testing has been performed. It is not exhaustive testing. To test, you need to compile with the macro `ORDER=i` where i:
* 0: Preorder
* 1: Inorder
* 2: Postorder

## Compiling
If using `gcc`

**Compile Test**
`gcc -Wall test.c preorder.h inorder.h postorder.h tree.h -DORDER=i`

To run `./a.out`
