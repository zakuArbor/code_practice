#include <stdlib.h>
#include "tree.h"

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = NULL;
    if (!root) {
        return (result);
    }
    int *arr = NULL;
    int size = 0;
    *returnSize = 0;
    if (root->left) {
        arr = postorderTraversal(root->left, &size);
	result = mergeTreeArray(size, arr, result, returnSize);
	size = 0;
    }
    if (root->right) {
        arr = postorderTraversal(root->right, &size);
	result = mergeTreeArray(size, arr, result, returnSize);
    }
    (*returnSize) += 1;
    result = realloc(result, (*returnSize) * sizeof(int));
    result[(*returnSize - 1)] = root->val;
    
    return(result);
}
