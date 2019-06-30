#include <stdlib.h>
#include "tree.h"

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = NULL;
    if (!root) {
        return (result);
    }
    int *left_arr = NULL, *right_arr = NULL;
    int left_size = 0, right_size = 0;
    int offset = 0;
    *returnSize = 0;
    if (root->left) {
        left_arr = postorderTraversal(root->left, &left_size);
    }
    if (root->right) {
        right_arr = postorderTraversal(root->right, &right_size);
    }
    *returnSize = left_size + right_size + 1;
    result = malloc(sizeof(int) * (*returnSize));
    
    for(int i = 0;i < left_size; i++) {
        *(result+i) = *(left_arr+i);
    }
    offset = left_size;
    for (int i = 0; i < right_size; i++) {
        *(result+offset+i) = *(right_arr+i);
    }
    *(result + *returnSize - 1) = root->val;
    
    if (left_arr) {
        free(left_arr);
    }
    if (right_arr) {
        free(right_arr);
    }
    
    return(result);
}
