class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        right_side = []
        current_level = -1
        q = deque([(root, 0)])
        while q:
            at, level = q.popleft()
            if level != current_level:
                current_level = level
                right_side.append(at.val)
            else:
                right_side[-1] = at.val
            if at.left:
                q.append((at.left, level + 1))
            if at.right:
                q.append((at.right, level + 1))
        return right_side
