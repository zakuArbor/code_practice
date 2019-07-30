# Binary Tree

## Implementations:
* Preorder Traversal
* Inorder Traversal
* Postorder Traversal
* Binary Search
* Insertion
* Deletion

## To Implement

## Testing

### Traversal Compilation 

Basic testing has been performed. It is not exhaustive testing. To test, you need to compile with the macro `ORDER=i` where i:
* 0: Preorder
* 1: Inorder
* 2: Postorder

**Compiling**
If using `gcc`

`gcc -Wall test.c preorder.h inorder.h postorder.h tree.h -DORDER=i`

To run `./a.out`

### Compilation of Binary Search, Insertion and Deletion Test

**Binary Search:** `gcc -Wall test_search.c test.h bst.h tree.h`

**Insertion:** `gcc -Wall test_insert.c test.h bst.h tree.h`

**Deletion:** `gcc -Wall test_delete.c test.h bst.h tree.h`
