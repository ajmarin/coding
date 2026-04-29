class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        c = Counter()

        def dfs(node, depth=0):
            if not node:
                return
            c[depth] += node.val
            depth += 1
            dfs(node.left, depth)
            dfs(node.right, depth)

        dfs(root)
        return c[max(c.keys())]
