# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])
        nodes = deque([root])
        for n in preorder[1:]:
            new_node = TreeNode(n)
            if n < nodes[-1].val:
                nodes[-1].left = new_node
            else:    
                while nodes and n > nodes[-1].val:
                    parent = nodes.pop()
                parent.right = new_node    
            nodes.append(new_node)
        return root