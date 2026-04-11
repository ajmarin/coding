class Solution:
    def longestZigZag(self, root: Optional[TreeNode], direction="", length=0) -> int:
        if not root:
            return length - 1

        if direction == "L":
            return max(
                self.longestZigZag(root.left, "L", 1),
                self.longestZigZag(root.right, "R", length + 1),
            )
        return max(
            self.longestZigZag(root.left, "L", length + 1),
            self.longestZigZag(root.right, "R", 1),
        )
