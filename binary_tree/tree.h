#if !defined(NULL)
#define NULL 0
#endif

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_node(int val, int left, int right) {
	struct TreeNode* node = malloc(sizeof(struct TreeNode));
	if (!node) {
		return(NULL);
	}
	node->val = val;
	node->left = left; 
	node->right = right;
	return(node);
}

