#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "bst.h"

void checkPass(int num, struct TreeNode *node) {
	if (node && node->val == num) {
                printf("PASS\n");
        }
        else {
                printf("FAIL\n");
        }
}

int main () {
	int tree[14] = {5, 3, 8, 2, 4, 6, 10, 0, 0, 0, 0, 0, 0, 9};
	struct TreeNode *node = NULL;
	struct TreeNode *root = NULL;
	int num;

	root = createNode(tree, NULL, 0, 0);
	printTestName(1, "Test Empty");
	if (node) {
		printf("FAIL\n");
	}
	else {
		printf("PASS\n");
	}

	printTestName(2, "Find node 3 - left child - height 1");
	num = 3;
	root = createNode(tree, NULL, 0, 14);
	node = bstRec(root, num);
	checkPass(num, node);

	printTestName(3, "Find node 8 - right child - height 1");	
	num = 8;
	node = bstRec(root, num);
        checkPass(num, node);

	printTestName(4, "Find node 2 - left subtree - height 2");
        num = 2;
        node = bstRec(root, num);
        checkPass(num, node);

	printTestName(5, "Find node 9 - right subtree - height 2");
        num = 9;
        node = bstRec(root, num);
        checkPass(num, node);

	printTestName(6, "Find non-existing node");
        num = 99;
        node = bstRec(root, num);
	if (node) {
                printf("FAIL\n");
        }
        else {
                printf("PASS\n");
        }
}
