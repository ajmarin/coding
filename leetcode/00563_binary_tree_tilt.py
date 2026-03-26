class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        if not root or root.right == root.left:
            return 0
        lval = rval = total_tilt = 0
        if root.right:
            total_tilt += self.findTilt(root.right)
            rval = root.right.val
            root.val += rval
        if root.left:
            total_tilt += self.findTilt(root.left)
            lval = root.left.val
            root.val += lval
        return total_tilt + abs(rval - lval)
