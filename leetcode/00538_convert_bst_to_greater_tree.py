# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def helper(root: TreeNode, add: int) -> int:
            if not root:
                return 0
            from_right = root.val + helper(root.right, add)
            root.val = from_right + add
            from_left = helper(root.left, root.val)
            return from_right + from_left
        helper(root, 0)
        return root