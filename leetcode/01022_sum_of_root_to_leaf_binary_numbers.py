# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, n: TreeNode, value: int) -> int:
        if n is None:
            return 0
        value = (value << 1) + n.val
        if n.left is None and n.right is None:
            return value
        return self.solve(n.left, value) + self.solve(n.right, value)

    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, 0)
