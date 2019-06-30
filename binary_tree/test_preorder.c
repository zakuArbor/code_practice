#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preorder.h"

#if (!defined(VERBOSE))
#define VERBOSE 0
#endif

/**
* For this implementation, 0 is not a valid value
*
**/

//extern struct TreeNode* createNode(int *tree_array, struct TreeNode *root, int i, int size);
extern int* preorderTraversal(struct TreeNode* root, int* returnSize);

int isEqual(int* expected, int *result, int expected_size, int result_size) {
	if (expected_size != result_size) {
		return(0);
	}
	for (int i = 0; i < expected_size; i++) {
		if (VERBOSE) 
			printf("\n\t%d (result) v.s %d (expected)\n", result[i], expected[i]);
		if (expected[i] && result[i] && expected[i] != result[i]) {
			return(0);
		}
	}
	return(1);
}

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d ", array[i]);
	}
}

void printBorder() {
	printf("======================\n");
}

void printTestName(int test, char *test_name) {
	printBorder();
	printf("%d. %s: ", test, test_name);
}

void checkPass(int *expected, int *result, int expected_size, int result_size) {
	if (isEqual(expected, result, expected_size, result_size)) {
                printf("PASS\n");
        }
	else {
		printf("FAIL\n");
	}
	printBorder();
}

int *mallocExpected(int size) {
	return malloc(sizeof(int) * size);
}

void cleanTest(int *result_size, int *result, struct TreeNode *root) {
	*result_size = 0;
	free(result);
	cleanTree(root);
}

int main () {
	int size = 0, result_size = 0;
	struct TreeNode *root = NULL;	
	int tree[14] = {5, 3, 8, 2, 4, 6, 10, 0, 0, 0, 0, 0, 0, 9};
	int expected[14]; //expected result for preorder

	printTestName(1, "Test Empty");
	int *result = NULL; //empty tree
	result = preorderTraversal(NULL, &result_size);
	checkPass(NULL, result, size, result_size); //expected = NULL to represent empty tree
	cleanTest(&result_size, result, root);

	expected[0] = 5;

	printTestName(2, "Root Node");
	size = 1;
	root = createNode(tree, NULL, 0, size);
	result = preorderTraversal(root, &result_size);
	checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	expected[1] = 3;

	printTestName(3, "Left Node");
	size = 2;
        root = createNode(tree, NULL, 0, size);
        result = preorderTraversal(root, &result_size);
        checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	expected[2] = 8;

	printTestName(3, "Right Node");
        size = 3;
        root = createNode(tree, NULL, 0, size);
        result = preorderTraversal(root, &result_size);
        checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	int expected_tree[8] = {5, 3, 2, 4, 8, 6, 10};

	printTestName(4, "Depth 3 - 7 Nodes");
	size = 7;
        root = createNode(tree, NULL, 0, size);
        result = preorderTraversal(root, &result_size);
        checkPass(expected_tree, result, size, result_size);
        cleanTest(&result_size, result, root);
}
