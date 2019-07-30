from typing import List
from math import floor, log

class Node:
	def __init__(self: 'Node', val: 'int' = None, left: 'Node' = None, right: 'Node' = None) -> None:
		''' 
		A new Node in a Binary Tree

		:param val: the value of the node
		:param left: the left child of the node (Constraint: all descendent of the left node are strictly less than the parent)
		:param right: the right child of the node (Constraint: all descendent of the right node are strictly greater than the parent)
		'''
		self._val = val;
		self._left = left;
		self._right = right;
	
	def getVal(self: 'Node') -> int:
		'''
		Return the value of the node

		>>> node = Node()
		>>> node.getVal() is None
		True
		>>> node = Node(1, None, None)
		>>> node.getVal()
		1
		'''
		return self._val;

	def setVal(self: 'Node', val: int) -> None:
		'''
		Set the value of the node
		
		>>> node = Node()
		>>> node._val is None
		True
		>>> node.setVal(1)
		>>> node._val
		1
		'''
		self._val = val

	def getLeft(self: 'Node') -> 'Node':
		'''
		Return the left child (Node)

		>>> node = Node()
		>>> node.getLeft() is None
		True
		>>> node = Node(5, Node(2))
		>>> node.getLeft()._val #we are assuming getVal does not work and for the sake of testing, we will break encapsulation rule
		2
		'''
		return self._left

	def setLeft(self: 'Node', left: 'Node' = None) -> None:
                '''
                Set right child

                >>> node = Node(5, None, None)
                >>> node.setLeft(Node(3))
                >>> node._left._val #assume none of other methods work for the sake of testing, wil break encapsulation rule
                3
                '''
                self._left = left;

	def getRight(self: 'Node') -> 'Node':
                '''
                Return the left child (Node)

                >>> node = Node()
                >>> node.getRight() is None
                True
                >>> node = Node(5, None, Node(8))
                >>> node.getRight()._val #we are assuming getVal does not work and for the sake of testing, we will break encapsulation rule
                8
                '''
                return self._right

	def setRight(self: 'Node', right: 'Node' = None) -> None:
		'''
		Set right child

		>>> node = Node(5, None, None)
		>>> node.setRight(Node(9))
		>>> node._right._val #assume none of other methods work for the sake of testing, wil break encapsulation rule
		9
		'''
		self._right = right;

	def insert(self: 'Node', val: int, root: 'Node' = None) -> None:
		'''
		Insert new node to the correct position in the binary tree

		>>> node = Node()
		>>> node.insert(5)
		>>> node.getVal()
		5
		>>> node = Node(5)
		>>> node.insert(3)
		>>> node.getLeft().getVal()
		3
		>>> node.insert(8)
		>>> node.getRight().getVal()
		8
		>>> node.insert(2)
		>>> node.getLeft().getLeft().getVal()
		2
		'''
		def helper(root: 'Node' = None, val: int = 0) -> 'Node':	
			if root:
				if root.getVal() > val:
					root.setLeft(helper(root.getLeft(), val))
				elif root.getVal() < val:
					root.setRight(helper(root.getRight(), val))
			else:
				return Node(val)
			return root
		if self.getVal():
			helper(self, val);			
		else:
			self.setVal(val)
	def search(self: 'Node', val: int) -> 'Node':
		'''
		Return the node that contains the val that we are searching for. Return None if not found
		>>> node = Node(1)
		>>> node.search(5) == None
		True
		>>> node = Node(5, Node(3), Node(7))
		>>> node.search(5) == node
		True
		>>> node.search(7) == node._right
		True
		>>> node.search(10) == None
		True
		'''
		def _helper(node: 'Node', val: int) -> 'Node':
			if node:
				if node._val == val:
					return node
				elif node._val > val: #left
					return _helper(node._left, val)
				else: #right
					return _helper(node._right, val)
			return None
		return _helper(self, val)

	def delete(self: 'Node', val: int) -> None:
		'''
		Delete the node from the tree if exist and return the new tree
		This implementation does not update the actual tree. User is responsible to update the tree accordingly

		>>> node = Node(5)
		>>> node.delete(5) == None
		True
		>>> node = Node(5, Node(3))
		>>> tmp = node.delete(3)
		>>> tmp._left == None
		True
		>>> tmp._val == 5
		True
		>>> node = Node(5, None, Node(7))
		>>> tmp = node.delete(7)
		>>> tmp._val == 5
		True
		>>> node =  Node(5, Node(3, Node(1)), Node(7, Node(6), Node(10)))
		>>> tmp = node.delete(5)
		>>> tmp._val == 6
		True
		>>> tmp._left._val == 3
		True
		>>> tmp._right._val == 7
		True
		>>> tmp._right._left == None
		True
		'''
		def _findMin(node: 'Node') -> Node:
			if node._left:
				return _findMin(node._left)
			return node
		def _helper(node: 'Node', val: int) -> Node:
			if node:
				if node._val > val: #left
                                        node._left = _helper(node._left, val)
				elif node._val < val: #right
                                        node._right = _helper(node._right, val)
				else: #node._val == val
					if not node._left and not node._right:
						node = None
					elif not node._left and node._right:
						node = None
						return node._right
					elif not node._right and node._left:
						node = None
						return node._left
					else:
						#two children - return the successor of the subtree which is the min of the right for this implementation
						tmp = _findMin(node._right)
						node._val = tmp._val
						node._right = _helper(node._right, tmp._val)
			return node
		return _helper(self, val)
				

def create_tree(arr: List[int]) -> Node:
	'''
	Create a binary tree based on the list and return the root of the tree
	
	number of nodes = 2^(h+1) - 1
	number of levels = floor(log_2(n))

	:param arr: a List of Int where:
		i*2: parent
		i*2+1: left child
		(i+1)*2: right child
	'''
	def helper(arr: List[int], pos: int) -> Node:
		size = len(arr)
		node = None
		if (i < size):
			node = Node(arr[i])
		
if __name__ == "__main__":
    import doctest
    doctest.testmod()
