# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def lca(root: TreeNode) -> (int, TreeNode):
            if not root:
                return 0, None
            left, lca_left = lca(root.left)
            right, lca_right = lca(root.right)
            if left == right:
                return left + 1, root
            return (left + 1, lca_left) if left > right else (right + 1, lca_right)
        return lca(root)[1]