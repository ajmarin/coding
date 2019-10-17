# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        total = root.val if L <= root.val and root.val <= R else 0
        if root.left:
            total += self.rangeSumBST(root.left, L, R)
        if root.right:
            total += self.rangeSumBST(root.right, L, R)
        return total