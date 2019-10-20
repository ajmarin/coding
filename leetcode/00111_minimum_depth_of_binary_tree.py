# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        MAX_DEPTH = 1 << 30
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        return 1 + min(self.minDepth(root.left) or MAX_DEPTH, self.minDepth(root.right) or MAX_DEPTH)