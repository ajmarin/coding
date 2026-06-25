class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 == root2:
            return True
        if (root1 is None) ^ (root2 is None):
            return False
        return root1.val == root2.val and (
            (
                self.flipEquiv(root1.left, root2.left)
                and self.flipEquiv(root1.right, root2.right)
            )
            or (
                self.flipEquiv(root1.right, root2.left)
                and self.flipEquiv(root1.left, root2.right)
            )
        )
