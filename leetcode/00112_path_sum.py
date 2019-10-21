# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, r: TreeNode, n: int) -> bool:
        if r is None:
            return False
        if r.left is None and r.right is None:
            return n == r.val
        n -= r.val
        return self.hasPathSum(r.left, n) or self.hasPathSum(r.right, n)