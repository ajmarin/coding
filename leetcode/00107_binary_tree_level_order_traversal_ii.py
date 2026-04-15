class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
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
                ans.append(level_values[:])
                current_level = level
                level_values = []
            level_values.append(node.val)
            q.append((node.left, level + 1))
            q.append((node.right, level + 1))
        return [level_values] + ans[::-1]
