class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        counts, totals = [], []
        q = deque([(root, 1)])
        while q:
            node, lvl = q.popleft()
            if node is None:
                continue
            if lvl > len(counts):
                counts.append(1)
                totals.append(node.val)
            else:
                counts[-1] += 1
                totals[-1] += node.val
            lvl += 1
            q.append((node.left, lvl))
            q.append((node.right, lvl))
        return [t / c for t, c in zip(totals, counts)]
