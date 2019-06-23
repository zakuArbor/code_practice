#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preorder.h"

/**
* For this implementation, 0 is not a valid value
*
**/

extern struct TreeNode* create_node(int val, int left, int right);
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

int main () {
	int test = 1, size = 0, result_size = 0;
	struct TreeNode *root = NULL;	
	char test_name[20];

	strncpy(test_name, "Test Empty", 10);
	test_name[10] = '\0';
	printTestName(1, "Test Empty");
	int *expected = NULL; //empty tree
	int *result = NULL; //empty tree
	result = preorderTraversal(NULL, &result_size);
	checkPass(expected, result, size, result_size);
	free(result);

	test = 2;
	size = 1;
	result_size = 0;
	strncpy(test_name, "Root Node", 9);
        test_name[9] = '\0';
	printTestName(test, test_name);
	if (!(expected = mallocExpected(size))) {
		exit(1);
	}
	expected[0] = 5;
	root = create_node(5, 0, 0);
	result = preorderTraversal(root, &result_size);
	checkPass(expected, result, size, result_size);	
}
