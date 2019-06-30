#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preorder.h"

/**
* For this implementation, 0 is not a valid value
*
**/

//extern struct TreeNode* create_node(int *tree_array, struct TreeNode *root, int i, int size);
extern int* preorderTraversal(struct TreeNode* root, int* returnSize);

int isEqual(int* expected, int *result, expected_size, result_size) {
	if (expected_size != result_size) {
		return(0);
	}
	printf("test\n");
	for (int i = 0; i < expected_size; i++) {
		if (expected[i] && result[i] && expected[i] != result[i]) {
			return(0);
		}
	}
	return(1);
}

void diffence(int*expected, int*result) {

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

void cleanup_test(int *result_size, int *result, struct TreeNode *root) {
	*result_size = 0;
	free(result);
	free(root);
}

int main () {
	int test = 1, size = 0, result_size = 0;
	struct TreeNode *root = NULL;	
	int *expected[14] = {5, 3, 8, 2, 4, 6, 10, 0, 0, 0, 0, 0, 0, 9};
	
	printTestName(1, "Test Empty");
	int *result = NULL; //empty tree
	result = preorderTraversal(NULL, &result_size);
	checkPass(NULL, result, size, result_size); //expected = NULL to represent empty tree
	cleanup_test(&result_size, result, root);

	printTestName(2, "Root Node");
	root = create_node(expected, NULL, 0, size);
	result = preorderTraversal(root, &result_size);
	checkPass(expected, result, size, result_size);
        cleanup_test(&result_size, result, root);
}
