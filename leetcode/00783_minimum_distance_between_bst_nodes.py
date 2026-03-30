class Solution:
    def __init__(self):
        self.ans = 10**6
        self.prev = -(10**6)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        if root.left:
            self.minDiffInBST(root.left)
        diff = root.val - self.prev
        self.ans = diff if diff < self.ans else self.ans
        self.prev = root.val
        if root.right:
            self.minDiffInBST(root.right)
        return self.ans
