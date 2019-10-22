# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def goleft(root, pos):
            while root.left:
                pos <<= 1
                root = root.left
            return pos
        def solve(root, pos):
            if root.left == root.right:
                return pos
            pl = goleft(root, pos)
            pr = goleft(root.right, 1 + (pos << 1)) if root.right else pos
            pos <<= 1
            if pr >= pl:
                return solve(root.right, pos + 1)
            return solve(root.left, pos)
        return solve(root, 1) if root else 0