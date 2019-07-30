#include "tree.h"

int* inorderTraversal(struct TreeNode *root, int *returnSize) {
    if (!root) 
        return(NULL);

    int *result = NULL;
    int *right_arr = NULL;
    int right_size = 0;
    *returnSize = 0;

    if (root->left) {
	result = inorderTraversal(root->left, returnSize);
        result = realloc(result, *returnSize * sizeof(int));
    } 
    else {
        result = malloc(sizeof(int));
    }
    *(result+*returnSize) = root->val;
    (*returnSize)++;
    
    if (root->right) {
        if((right_arr = inorderTraversal(root->right, &right_size))) {
	    for (int i = 0; i < right_size; i++) {
	        *(result+*returnSize+i) = *(right_arr+i);
	    }
	    *returnSize += right_size;
	    free(right_arr);
	}
    }    
    return(result);
}

