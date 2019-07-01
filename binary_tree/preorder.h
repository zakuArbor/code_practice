#include "tree.h"

int *mergeTree(int size, int *arr, int *result, int *returnSize) {
	if (size) {
		result = realloc(result, (*returnSize + size) * sizeof(int));
		for (int i = 0; i < size; i++) {
		        *(result+(*returnSize)+i) = *(arr+i);
    		}
		(*returnSize) += size;
		free(arr);
	}
	return(result);
}

int* preorderTraversal(struct TreeNode *root, int *returnSize) {
    if (!root) {
        return(NULL);
    }
    int left_size = 0, right_size = 0;
    int *result = malloc(sizeof(int));
    int *left_arr = NULL;
    int *right_arr = NULL;
    *result = root->val;
    *returnSize = 1;
    if (root->left) {
        left_arr = preorderTraversal(root->left, &left_size);
	result = mergeTree(left_size, left_arr, result, returnSize);
    }
    if (root->right) {
        right_arr = preorderTraversal(root->right, &right_size);
	result = mergeTree(right_size, right_arr, result, returnSize);
    }
    return(result);
}

