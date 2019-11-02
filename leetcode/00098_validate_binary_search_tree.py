# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode, left: int = None, right: int = None) -> bool:
        if not root:
            return True
        if left is not None and root.val <= left:
            return False
        if right is not None and root.val >= right:
            return False
        return self.isValidBST(root.left, left, root.val) and self.isValidBST(root.right, root.val, right)