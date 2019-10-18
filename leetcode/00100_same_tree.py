# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if (p is None)^(q is None):
            return False
        if p is None:
            return True
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)