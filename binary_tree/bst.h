#include "tree.h"

struct TreeNode* search(struct TreeNode *node, int i) {
	if (node) {
		if (node->val > i) 
			return search(node->left, i);
		else if (node->val < i)
			return search(node->right, i);
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

struct TreeNode* find_min(struct TreeNode *node) {
        struct TreeNode *curr = node;
        while (curr) {
                if (!curr->left) {
                        break;
                }
                curr = curr->left;
        }
        return(curr);
}

struct TreeNode* delete_node(struct TreeNode *node, int i) {
        if (!node) {
                return(node);
        }
        if (node->val > i) {
                node->left = delete_node(node->left, i);
        }
        else if (node->val < i) {
                node->right = delete_node(node->right, i);
        }
        else {
                struct TreeNode *tmp = NULL;

                //one child only
                if (!node->left) {
                        tmp = node->right;
                        free(node);
                        node = NULL;
                        return(tmp);
                }
                else if (!node->right) {
                        tmp = node->left;
                        free(node);
                        node = NULL;
                        return(tmp);
                }
                //2 children - get the successor (the min of the right subtree)
                tmp = find_min(node->right);
                node->val = tmp->val;
                //delete the successor node since we replaced the node with the successor value
		node->right = delete_node(node->right, node->val);
        }
	return(node);
}
