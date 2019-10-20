# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def depth(self, n: TreeNode) -> int:
        if n is None:
            return 0
        depth = getattr(n, 'depth', None)
        if depth is None:
            n.depth = 1 + max(self.depth(n.left), self.depth(n.right)) if n else 0
        return n.depth

    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        if abs(self.depth(root.left) - self.depth(root.right)) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)