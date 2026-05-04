class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        adj = defaultdict(list)

        def tree_dfs(node: TreeNode, p: TreeNode):
            if not node:
                return
            if p:
                adj[node.val].append(p.val)
                adj[p.val].append(node.val)
            tree_dfs(node.left, node)
            tree_dfs(node.right, node)

        ans = []

        def dist_dfs(u: int, parent=-1, d=0):
            if d == k:
                ans.append(u)
                return
            for v in adj[u]:
                if v != parent:
                    dist_dfs(v, u, d + 1)

        tree_dfs(root, None)
        dist_dfs(target.val)
        return ans
