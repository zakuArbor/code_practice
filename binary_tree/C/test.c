#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preorder.h"
#include "postorder.h"
#include "inorder.h"

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

#ifndef ORDER 
#define ORDER preorder
#endif

#if (!defined(VERBOSE))
#define VERBOSE 0
#endif

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
	int tree2[7] = {1, 0, 3, 0, 0, 2, 0};
	int expected[14];

	int* (*traversal) (struct TreeNode*, int*);
	switch (ORDER) {
		case PREORDER:
			traversal = preorderTraversal;
			break;
		case POSTORDER:
			traversal = postorderTraversal;
			break;
		case INORDER:
			traversal = inorderTraversal;
	}


	printTestName(1, "Test Empty");
	int *result = NULL; //empty tree
	result = traversal(NULL, &result_size);
	checkPass(NULL, result, size, result_size); //expected = NULL to represent empty tree
	cleanTest(&result_size, result, root);

	expected[0] = 5;

	printTestName(2, "Root Node");
	size = 1;
	root = createTree(tree, NULL, 0, size);
	result = traversal(root, &result_size);
	checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	#if ORDER == PREORDER
	expected[1] = 3;
	#elif ORDER == POSTORDER
	expected[0] = 3;
	expected[1] = 5;
	#elif ORDER == INORDER
	expected[0] = 3;
	expected[1] = 5;
	#endif

	printTestName(3, "Left Node");
	size = 2;
        root = createTree(tree, NULL, 0, size);
        result = traversal(root, &result_size);
        checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	#if ORDER == PREORDER
	expected[2] = 8;
	#elif ORDER == POSTORDER
	expected[0] = 3;
	expected[1] = 8;
	expected[2] = 5;
	#elif ORDER == INORDER
        expected[0] = 3;
        expected[1] = 5;
	expected[2] = 8; 
	#endif

	printTestName(3, "Left and Right Node");
        size = 3;
        root = createTree(tree, NULL, 0, size);
        result = traversal(root, &result_size);
        checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);

	#if ORDER == PREORDER
        expected[2] = 2;
	expected[3] = 4;
	expected[4] = 8;
        #elif ORDER == POSTORDER
        expected[0] = 2;
        expected[1] = 4;
        expected[2] = 3;
	expected[3] = 8;
	expected[4] = 5;
        #elif ORDER == INORDER
        expected[0] = 2;
        expected[1] = 3;
        expected[2] = 4;
	expected[3] = 5;
	expected[4] = 8;
        #endif

	printTestName(4, "Height 2 - 5 Nodes");
        size = 5;
        root = createTree(tree, NULL, 0, size);
        result = traversal(root, &result_size);
        checkPass(expected, result, size, result_size);
        cleanTest(&result_size, result, root);


	#if ORDER == PREORDER
	int expected_tree[8] = {5, 3, 2, 4, 8, 6, 10};
	#elif ORDER == POSTORDER
	int expected_tree[8] = {2, 4, 3, 6, 10, 8, 5};
	#elif ORDER == INORDER
	int expected_tree[8] = {2, 3, 4, 5, 6, 8, 10};
	#endif

	printTestName(5, "Depth 3 - 7 Nodes");
	size = 7;
        root = createTree(tree, NULL, 0, size);
        result = traversal(root, &result_size);
        checkPass(expected_tree, result, size, result_size);
        cleanTest(&result_size, result, root);

	#if ORDER == PREORDER
        int expected_tree2[3] = {1, 3, 2};
        #elif ORDER == POSTORDER
        int expected_tree2[3] = {2, 3, 1};
        #elif ORDER == INORDER
        int expected_tree2[3] = {1, 2, 3};
        #endif

	printTestName(6, "Right subtree: Depth 2 - 3 Nodes");
        size = 3;
        root = createTree(tree2, NULL, 0, 7);
        result = traversal(root, &result_size);printArray(result, result_size);
        checkPass(expected_tree2, result, size, result_size);
        cleanTest(&result_size, result, root);
}
