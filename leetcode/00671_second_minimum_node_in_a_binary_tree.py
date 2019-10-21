# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMinimumBiggerThan(self, root: TreeNode, value: int) -> int:
        if root.left is None and root.right is None:
            return root.val if root.val != value else -1
        left = self.findMinimumBiggerThan(root.left, value)
        right = self.findMinimumBiggerThan(root.right, value)
        if left != -1 and right != -1:
            return min(left, right)
        if left != -1:
            return left
        return right

    def findSecondMinimumValue(self, root: TreeNode) -> int:
        return self.findMinimumBiggerThan(root, root.val)