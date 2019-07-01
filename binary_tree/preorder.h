#include "tree.h"

int* preorderTraversal(struct TreeNode *root, int *returnSize) {
    if (!root) {
        return(NULL);
    }
    int size = 0;
    int *result = malloc(sizeof(int));
    int *arr = NULL;
    *result = root->val;
    *returnSize = 1;
    if (root->left) {
        arr = preorderTraversal(root->left, &size);
	result = mergeTreeArray(size, arr, result, returnSize);
    }
    if (root->right) {
        arr = preorderTraversal(root->right, &size);
	result = mergeTreeArray(size, arr, result, returnSize);
    }
    return(result);
}

