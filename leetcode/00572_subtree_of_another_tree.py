class Solution:
    def match(self, a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
        if a == b:
            return True
        if a and b:
            return (
                a.val == b.val
                and self.match(a.left, b.left)
                and self.match(a.right, b.right)
            )
        return False

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot is None:
            return True
        if not root:
            return False

        return (
            self.match(root, subRoot)
            or self.isSubtree(root.left, subRoot)
            or self.isSubtree(root.right, subRoot)
        )
