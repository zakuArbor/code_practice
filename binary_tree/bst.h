#include "tree.h"

struct TreeNode* bstRec(struct TreeNode *node, int i) {
	if (node) {
		if (node->val > i) 
			return bstRec(node->left, i);
		else if (node->val < i)
			return bstRec(node->right, i);
	}
	return(node); //either target or null
}

void insertNode(struct TreeNode **node, int i) {
	if (*node) {
		if ((*node)->val > i) 
			insertNode(&((*node)->left), i);
		else if ((*node)->val < i) 
			insertNode(&((*node)->right), i);
	} 
	else {
		*node = malloc(sizeof(struct TreeNode));
		(*node)->val = i;
		(*node)->left = NULL;
		(*node)->right = NULL;
	}
}
