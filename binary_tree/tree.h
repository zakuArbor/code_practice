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
* param tree: an array of int
* 	constraint: following rules apply:
* 		parent node = i
* 		left node   = i*2 + 1
* 		right node  = (i+1) * 2
*/
struct TreeNode* create_node(int *tree_array, struct TreeNode *root, int i, int size) {
	struct TreeNode * node = NULL;
	if (i < size) {
		node = malloc(sizeof(struct TreeNode));
		node->val = tree_array[i];
		node->left = create_node(tree_array, node, i*2 + 1, size);
		node->right = create_node(tree_array, node, (i+1) * 2, size);
	}
	return(node);
}
