class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode], parity=0) -> int:
        def dfs(node, parity):
            if not node:
                return 0
            parity ^= 1 << node.val
            if node.left == node.right:
                return int(parity & (parity - 1) == 0)
            return dfs(node.left, parity) + dfs(node.right, parity)

        return dfs(root, 0)
