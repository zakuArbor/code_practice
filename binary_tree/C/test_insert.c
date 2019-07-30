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
}


int main () {
//	int expected_array[15] = {9, 5, 14, 3, 8, 10, 20, 2, 4, 6, 0, 11, 13, 18, 0};
	int tree_array[15];
	struct TreeNode *expected_tree = NULL;
	struct TreeNode *actual_tree = NULL;
	int num;

	printTestName(1, "Insert into empty tree");
	num = 9;
	tree_array[0] = num;
	tree_array[1] = 0;
	tree_array[2] = 0;
	expected_tree = createTree(tree_array, NULL, 0, 1);
	insertNode(&actual_tree, num);
	checkPass(expected_tree, actual_tree);

        printTestName(2, "Height 1: Insert left child - 2 nodes");
	num = 5;
	tree_array[1] = num;
	expected_tree = createTree(tree_array, NULL, 0, 2);
	insertNode(&actual_tree, num); 
	checkPass(expected_tree, actual_tree);

	free(actual_tree);
	actual_tree = NULL;
	printTestName(2, "Height 1: Insert right child - 2 nodes");
        num = 14;
	tree_array[1] = 0;
        tree_array[2] = num;
        expected_tree = createTree(tree_array, NULL, 0, 3);
	insertNode(&actual_tree, 9);
        insertNode(&actual_tree, num);
        checkPass(expected_tree, actual_tree);

	printTestName(3, "Height 1: Complete Level 1 - 3 nodes");
        num = 14;
        tree_array[1] = 5;
        tree_array[2] = num;
        expected_tree = createTree(tree_array, NULL, 0, 3);
        insertNode(&actual_tree, 9);
        insertNode(&actual_tree, 5);
        insertNode(&actual_tree, num);
        checkPass(expected_tree, actual_tree);

	printTestName(4, "Height 2: Insert in Right Subtree Right Child - 4 nodes");
	num = 20;
	tree_array[3] = 0;
	tree_array[4] = 0;
	tree_array[5] = 0;
	tree_array[6] = 20;
        insertNode(&actual_tree, num);
        expected_tree = createTree(tree_array, NULL, 0, 7);
        checkPass(expected_tree, actual_tree);

        printTestName(5, "Height 2: Insert in Left Subtree Right Child - 5 nodes");
        num = 8;
        tree_array[4] = num;
        insertNode(&actual_tree, num);
        expected_tree = createTree(tree_array, NULL, 0, 7);
        checkPass(expected_tree, actual_tree); 

	printTestName(6, "Height 2: Complete Right Subtree Insert Left Child - 6 nodes");
        num = 10;
        tree_array[5] = num;
        insertNode(&actual_tree, num);
        expected_tree = createTree(tree_array, NULL, 0, 7);
        checkPass(expected_tree, actual_tree);

	printTestName(6, "Height 2: Complete Left Subtree Insert Left Child - 7 nodes");
        num = 3;
        tree_array[3] = num;
        insertNode(&actual_tree, num);
        expected_tree = createTree(tree_array, NULL, 0, 7);
        checkPass(expected_tree, actual_tree);

}
