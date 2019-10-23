# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.total = 0
        def dfs(n: TreeNode, v: int) -> None:
            if not n:
                return
            v += n.val
            if n.left is None and n.right is None:
                self.total += v
                return
            dfs(n.left, 10*v)
            dfs(n.right, 10*v)
        dfs(root, 0)
        return self.total