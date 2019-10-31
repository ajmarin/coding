# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        inorder = collections.deque()
        def dfs(root: TreeNode):
            if root.left:
                dfs(root.left)
            inorder.append(root.val)
            if root.right:
                dfs(root.right)
        dfs(root)
        return min(inorder[i] - inorder[i - 1] for i in range(1, len(inorder)))