class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        d, p = {}, {}
        def dfs(node: TreeNode, parent: int, depth: int) -> None:
            if node is None:
                return
            v = node.val
            d[v] = depth
            p[v] = parent
            dfs(node.left, v, depth + 1)
            dfs(node.right, v, depth + 1)
        dfs(root, -1, 0)
        return d[x] == d[y] and p[x] != p[y]