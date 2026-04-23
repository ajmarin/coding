class Solution:
    def levelOrder(self, root: "Node") -> List[List[int]]:
        if not root:
            return []
        q = deque([(root, 0)])
        ans = []
        curr_level, level_values = 0, []
        while q:
            at, level = q.popleft()
            if level != curr_level:
                curr_level = level
                ans.append(level_values)
                level_values = []
            level += 1
            q.extend([(child, level) for child in at.children])
            level_values.append(at.val)
        ans.append(level_values)
        return ans
