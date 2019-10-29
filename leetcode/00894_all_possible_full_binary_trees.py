# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import functools
class Solution:
    leaf = TreeNode(0)
    @functools.lru_cache(None)
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        answer = collections.deque()
        if not N & 1:
            return answer
        if N == 1:
            answer.append(self.leaf)
        for i in range(1, N, 2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(N - 1 - i)
            for rl in left:
                for rr in right:
                    root = TreeNode(0)
                    root.left = rl
                    root.right = rr
                    answer.append(root)
        return answer