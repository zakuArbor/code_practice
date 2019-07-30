#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "bst.h"

int treeEqual(struct TreeNode *expected_tree, struct TreeNode *actual_tree) { 
	int equalFlag = 0; //default false
	if ((expected_tree && !actual_tree) || (!expected_tree && actual_tree)) { //true iff both trees are not in the same state (i.e. NULL or not NULL)
		return(0);
	} 
	else if (!expected_tree && !actual_tree) {
		return(1);
	}
	
	if (expected_tree->val != actual_tree->val) {
		return(0);
	}
	else {
		equalFlag = 1;
	}
	
	equalFlag &= treeEqual(expected_tree->left, actual_tree->left);
	equalFlag &= treeEqual(expected_tree->right, actual_tree->right);
	return(equalFlag);
}

void checkPass(struct TreeNode *expected_tree, struct TreeNode *actual_tree) {
        if (treeEqual(expected_tree, actual_tree)) {
                printf("PASS\n");
        }
        else {
                printf("FAIL\n");
        }
        printBorder();
        cleanTree(expected_tree);
	cleanTree(actual_tree);
	expected_tree = NULL;
	actual_tree = NULL;
}


int main () {
//	int expected_array[15] = {9, 5, 14, 3, 8, 10, 20, 2, 4, 6, 0, 11, 13, 18, 0};
	int expected_array[15];
	int tree_array[15];
	int size_array = 0;
	struct TreeNode *expected_tree = NULL;
	struct TreeNode *actual_tree = NULL;
	int num;

	printTestName(1, "Delete into empty tree");
	num = 9;
	expected_tree = createTree(tree_array, NULL, 0, size_array);
	actual_tree = createTree(tree_array, NULL, 0, size_array);
	actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);

        printTestName(2, "Height 0: Delete Root node");
	num = 9;
	size_array = 0;
	tree_array[0] = num;
	expected_tree = createTree(tree_array, NULL, 0, size_array);
	actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);

	printTestName(3, "Height 1: Delete root - has Left child only");
        num = 9;
	size_array = 1;
	expected_array[0] = 5;
	tree_array[1] = 5;
        expected_tree = createTree(expected_array, NULL, 0, size_array);
	size_array = 2;
	actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
        checkPass(expected_tree, actual_tree);

	printTestName(4, "Height 1: Delete root  - has right child only");
        num = 9;
        size_array = 1;
	expected_array[0] = 14;
        expected_array[1] = 0;
	tree_array[0] = 9;
	tree_array[1] = 0;
        tree_array[2] = 14;
        expected_tree = createTree(expected_array, NULL, 0, size_array);
        size_array = 3;
        actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);

        printTestName(5, "Height 1: Delete root - has two children");
        num = 9;
	size_array = 2;
        expected_array[0] = 14;
        expected_array[1] = 5;
	expected_array[2] = 0;
        tree_array[0] = 9;
        tree_array[1] = 5;
	tree_array[2] = 14;
        expected_tree = createTree(expected_array, NULL, 0, size_array);
        size_array = 3;
        actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);
 

	printTestName(6, "Height 2: Delete Right Node - Complete Right Subtree - Initial: 5 nodes" );
        num = 9;
        size_array = 7;
        expected_array[0] = 10;
        expected_array[1] = 5;
        expected_array[2] = 14;
	expected_array[3] = 0;
	expected_array[4] = 0;
	expected_array[5] = 0;
	expected_array[6] = 20;
        tree_array[0] = 9;
        tree_array[1] = 5;
        tree_array[2] = 14;
	tree_array[3] = 0;
        tree_array[4] = 0;
	tree_array[5] = 10;
	tree_array[6] = 20;
	expected_tree = createTree(expected_array, NULL, 0, size_array);
        size_array = 7;
        actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);

	printTestName(7, "Height 2: Complete Left Subtree - Delete root - 5 initial nodes");
	num = 9;
	size_array = 5;
        expected_array[0] = 14;
        expected_array[1] = 5;
        expected_array[2] = 0;
        expected_array[3] = 3;
        expected_array[4] = 8;
        expected_array[5] = 0;
        expected_array[6] = 0;
        tree_array[0] = 9;
        tree_array[1] = 5;
        tree_array[2] = 14;
        tree_array[3] = 3;
        tree_array[4] = 8;
        tree_array[5] = 0;
        tree_array[6] = 0;
        expected_tree = createTree(expected_array, NULL, 0, size_array);
        size_array = 7;
        actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
	checkPass(expected_tree, actual_tree);

	printTestName(8, "Height 2: Complete Left Subtree only - Delete root - 4 initial nodes");
        num = 9;
        size_array = 3;
        expected_array[0] = 5;
        expected_array[1] = 3;
        expected_array[2] = 8;
        expected_array[3] = 0;
        expected_array[4] = 0;
        expected_array[5] = 0;
        expected_array[6] = 0;
        tree_array[0] = 9;
        tree_array[1] = 5;
        tree_array[2] = 0;
        tree_array[3] = 3;
        tree_array[4] = 8;
        tree_array[5] = 0;
        tree_array[6] = 0;
        expected_tree = createTree(expected_array, NULL, 0, size_array);
        size_array = 5;
        actual_tree = createTree(tree_array, NULL, 0, size_array);
        actual_tree = delete_node(actual_tree, num);
        checkPass(expected_tree, actual_tree);
}
