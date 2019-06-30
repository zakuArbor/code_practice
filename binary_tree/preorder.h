#include "tree.h"

int* preorderTraversal(struct TreeNode *root, int *returnSize) {
    if (!root) {
        return(NULL);
    }
    int left_size = 0, right_size = 0;
    int *result = malloc(sizeof(int));
    int *left_arr = NULL;
    int *right_arr = NULL;
    int offset = 1;
    *result = root->val;
    if (root->left) {
        left_arr = preorderTraversal(root->left, &left_size);
    }
    if (root->right) {
        right_arr = preorderTraversal(root->right, &right_size);
    }
    (*returnSize) = 1 + left_size + right_size;
    if (left_size || right_size) {
        result = realloc(result, (*returnSize) * sizeof(int));
    }

    for (int i = 0; i < left_size; i++) {
        *(result+offset+i) = *(left_arr+i);
    }

    offset = 1 + left_size;
    for (int i = 0; i < right_size; i++) {
        *(result+offset+i) = *(right_arr+i);
    }
    free(left_arr);
    free(right_arr);

    return(result);
}

