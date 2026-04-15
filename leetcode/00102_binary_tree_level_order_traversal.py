class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = deque([(root, 0)])
        current_level = 0
        ans, level_values = [], []
        while q:
            node, level = q.popleft()
            if node is None:
                continue
            if level != current_level:
                current_level = level
                ans.append(level_values[:])
                level_values = []
            level_values.append(node.val)
            q.append((node.left, level + 1))
            q.append((node.right, level + 1))
        return ans + [level_values]
