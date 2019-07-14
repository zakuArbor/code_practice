from node import Node
from typing import List

def print_array(lst: List[int]):
	for i in lst:
		print(i)

def preorderTraversal(root: 'Node') -> List[int]:
	'''
	Returns a list of int ordered in preorder travseral

	>>> lst = preorderTraversal(None)
	>>> print_array(lst)
	>>> lst = preorderTraversal(Node(5))
	>>> print_array(lst)
	5
	>>> lst = preorderTraversal(Node(5, Node(3), Node(8)))
	>>> print_array(lst)
	5
	3
	8
	>>> lst = preorderTraversal(Node(5, Node(3, Node(2), Node(4)), Node(8, Node(6), Node(10))))
	>>> print_array(lst)
	5
	3
	2
	4
	8
	6
	10
	'''
	arr = []
	if not root:
		return arr
	arr.append(root.getVal())
	arr += preorderTraversal(root.getLeft())
	arr += preorderTraversal(root.getRight())
	return arr

def inorderTraversal(root: 'Node') -> List[int]:
	'''
	Returns a list of int ordered in inorder traversal
	
	>>> lst = inorderTraversal(None)
	>>> print_array(lst)
        >>> lst = inorderTraversal(Node(5))
        >>> print_array(lst)
        5
        >>> lst = inorderTraversal(Node(5, Node(3), Node(8)))
        >>> print_array(lst)
        3
	5
        8
        >>> lst = inorderTraversal(Node(5, Node(3, Node(2), Node(4)), Node(8, Node(6), Node(10))))
        >>> print_array(lst)
	2
	3
	4
	5
	6
	8
	10
	'''
	arr = []
	if (root):
		arr += inorderTraversal(root.getLeft())
		arr.append(root.getVal())
		arr += inorderTraversal(root.getRight())
	return arr

def postorderTraversal(root: 'Node') -> List[int]:
	'''
	Return a list of int ordered in postorder traversal

	>>> lst = postorderTraversal(None)
        >>> print_array(lst)
        >>> lst = postorderTraversal(Node(5))
        >>> print_array(lst)
        5
        >>> lst = postorderTraversal(Node(5, Node(3), Node(8)))
        >>> print_array(lst)
        3
        8
	5
        >>> lst = postorderTraversal(Node(5, Node(3, Node(2), Node(4)), Node(8, Node(6), Node(10))))
        >>> print_array(lst)
	2
	4
	3
	6
	10
	8
	5
	'''

	arr = []
	if (root):
		arr += postorderTraversal(root.getLeft())
		arr += postorderTraversal(root.getRight())
		arr.append(root.getVal())
	return arr
