# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        buckets = collections.defaultdict(collections.deque)
        q = collections.deque([(0, 0, root)])
        while q:
            x, y, node = q.pop()
            buckets[x].append((y, node.val))
            if node.left:
                q.append((x - 1, y + 1, node.left))
            if node.right:
                q.append((x + 1, y + 1, node.right))
        return [map(lambda v: v[1], sorted(buckets[x])) for x in sorted(buckets)]