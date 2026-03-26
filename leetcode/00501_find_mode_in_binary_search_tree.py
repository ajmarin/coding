class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        c = Counter()

        def dfs(node):
            if not node:
                return
            dfs(node.left)
            c[node.val] += 1
            dfs(node.right)

        dfs(root)

        maxval = max(c.values())
        return [k for k, cnt in c.items() if cnt == maxval]
