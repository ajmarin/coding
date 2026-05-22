class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        total = 0
        q = deque([root])
        while q:
            node = q.popleft()
            total += node.val
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0, 0
            left, left_max = dfs(node.left)
            right, right_max = dfs(node.right)
            rem_left = (total - left) * left
            rem_right = (total - right) * right
            return left + right + node.val, max(
                left_max, right_max, rem_left, rem_right
            )

        return dfs(root)[1] % (10**9 + 7)
