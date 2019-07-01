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
