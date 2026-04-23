class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, 0)])
        curr_level = 0
        values = []
        while q:
            at, level = q.popleft()
            if not at:
                continue
            if level != curr_level:
                values = []
                curr_level = level
            values.append(at.val)
            q.append((at.left, level + 1))
            q.append((at.right, level + 1))
        return values[0]
