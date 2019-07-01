#include <stdlib.h>

#ifndef TREE_H
#define TREE_H
#if !defined(NULL)
#define NULL 0
#endif

#define LEFT_CHILD(i) (i * 2 + 1)
#define RIGHT_CHILD(i) ((i + 1) * 2)

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
* Create binary tree
*
* Note: 0 is not considered a valid value
*
* param tree: an array of int
* 	constraint: following rules apply:
* 		parent node = i
* 		left node   = i*2 + 1
* 		right node  = (i+1) * 2
*/
struct TreeNode* createTree(int *tree_array, struct TreeNode *root, int i, int size) {
	struct TreeNode * node = NULL;
	if (i < size && tree_array[i]) {
		node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		node->val = tree_array[i];
		node->left = createTree(tree_array, node, i*2 + 1, size);
		node->right = createTree(tree_array, node, (i+1) * 2, size);
	}
	return(node);
}

void cleanTree(struct TreeNode *root) {
	if (root) {
		cleanTree(root->left);
		cleanTree(root->right);
		free(root);
	}
}

int *mergeTreeArray(int size, int *arr, int *result, int *returnSize) {
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

#endif
