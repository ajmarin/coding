class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        if root.val < 2:
            return True if root.val else False
        left = self.evaluateTree(root.left)
        right = self.evaluateTree(root.right)
        return left or right if root.val == 2 else left and right
