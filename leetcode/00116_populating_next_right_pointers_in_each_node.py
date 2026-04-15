class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        q = deque([(root, 0)])
        prev = None
        curr_level = 0
        while q:
            node, level = q.popleft()
            if not node:
                continue
            if level != curr_level:
                prev.right = prev = None
                curr_level = level
            elif prev:
                prev.next = node
            q.append((node.left, level + 1))
            q.append((node.right, level + 1))
            prev = node
        return root
