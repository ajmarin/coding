class Solution:
    def goodNodes(self, root: TreeNode, maxval=-inf) -> int:
        maxval = root.val if root.val > maxval else maxval
        left = self.goodNodes(root.left, maxval) if root.left else 0
        right = self.goodNodes(root.right, maxval) if root.right else 0
        return left + right + (maxval == root.val)
