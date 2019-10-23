# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.answer = 0
        def get_length(n: TreeNode) -> int:
            if n is None:
                return 0
            left_length = get_length(n.left)
            right_length = get_length(n.right)
            left = left_length + 1 if n.left and n.left.val == n.val else 0
            right = right_length + 1 if n.right and n.right.val == n.val else 0
            self.answer = max(self.answer, left + right)
            return max(left, right)
        get_length(root)
        return self.answer