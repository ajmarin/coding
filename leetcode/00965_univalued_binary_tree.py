class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        v = root.val
        return (
            root.left is None or (v == root.left.val and self.isUnivalTree(root.left))
        ) and (
            root.right is None
            or (v == root.right.val and self.isUnivalTree(root.right))
        )
