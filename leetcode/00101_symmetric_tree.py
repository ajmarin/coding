# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def symmetric(self, left: TreeNode, right: TreeNode) -> None:
        if (left is None)^(right is None):
            return False
        if left == right:
            return True
        return (
            left.val == right.val and 
            self.symmetric(left.left, right.right) and 
            self.symmetric(left.right, right.left)
        )

    def isSymmetric(self, root: TreeNode) -> bool:
        return root is None or self.symmetric(root.left, root.right)