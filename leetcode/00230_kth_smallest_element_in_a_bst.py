class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        values = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            values.append(node.val)
            if len(values) >= k:
                return
            inorder(node.right)

        inorder(root)
        return values[k - 1]
