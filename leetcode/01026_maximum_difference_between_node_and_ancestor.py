class Solution:
    def solve(self, node: Optional[TreeNode], low, high) -> int:
        if not node:
            return 0
        ans = max(abs(node.val - low), abs(node.val - high))
        low = low if low < node.val else node.val
        high = high if high > node.val else node.val
        return max(
            ans,
            self.solve(node.left, low, high),
            self.solve(node.right, low, high),
        )

    def maxAncestorDiff(self, root: Optional[TreeNode], low=inf, high=-inf) -> int:
        return self.solve(root, root.val, root.val)
