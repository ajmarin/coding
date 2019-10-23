# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        answer = []
        if not root:
            return answer
        q = collections.deque([(root, 0)])
        level, maxval = -1, 0
        while q:
            node, nlevel = q.popleft()
            if level != nlevel:
                if level != -1:
                    answer.append(maxval)
                maxval = node.val
                level = nlevel
            else:
                maxval = max(maxval, node.val)
            if node.left:
                q.append((node.left, nlevel + 1))
            if node.right:
                q.append((node.right, nlevel + 1))
        answer.append(maxval)
        return answer