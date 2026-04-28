class Solution:
    def getHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))

    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        if not root:
            return []
        height = self.getHeight(root)
        width = (1 << height) - 1
        ans = [[""] * width for _ in range(height)]

        def dfs(level, node, pos):
            if not node:
                return
            ans[level][pos] = str(node.val)
            if (level := level + 1) == height:
                return
            delta = 1 << (height - 1 - level)
            dfs(level, node.left, pos - delta)
            dfs(level, node.right, pos + delta)

        dfs(0, root, width >> 1)
        return ans
