class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        q = deque([root])
        prev = None
        while q:
            curr = q.pop()
            if not curr:
                continue
            if prev:
                prev.right = curr
            q.append(curr.right)
            q.append(curr.left)
            curr.left = None
            prev = curr
        return root
