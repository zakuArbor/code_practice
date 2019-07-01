# Binary Tree

## Implementations:
* Preorder Traversal
* Inorder Traversal
* Postorder Traversal

## To Implement
* Binary Search Tree

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
