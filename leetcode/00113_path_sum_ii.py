# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.answer = collections.deque()
        self.path = collections.deque()

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        self.path.append(root.val)
        if root.left is None and root.right is None and sum == root.val:
            self.answer.append(list(self.path))
        if root.left:
            self.pathSum(root.left, sum - root.val)
        if root.right:
            self.pathSum(root.right, sum - root.val)
        self.path.pop()
        return self.answer