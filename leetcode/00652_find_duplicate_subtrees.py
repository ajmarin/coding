# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        answer = []
        count = collections.defaultdict(int)
        def dfs(n: TreeNode):
            if not n:
                return '%'
            key = '/'.join([str(n.val), dfs(n.left), dfs(n.right)])
            if count[key] + 1 == 2:
                answer.append(n)
            count[key] += 1
            return key
        dfs(root)
        return answer