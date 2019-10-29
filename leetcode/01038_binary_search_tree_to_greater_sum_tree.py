# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(node: TreeNode, s: int = 0) -> int:
            if node is None:
                return 0
            right = dfs(node.right, s)
            node.val += s + right
            return node.val - s + dfs(node.left, node.val)
        dfs(root, 0)
        return root