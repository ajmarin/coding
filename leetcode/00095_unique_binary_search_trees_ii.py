class Solution:
    def generateTrees(self, end: int, start: int = 1) -> List[Optional[TreeNode]]:
        if start > end:
            return [None]
        ans = []
        for mid in range(start, end + 1):
            left_opts = self.generateTrees(mid - 1, start)
            right_opts = self.generateTrees(end, mid + 1)
            for left, right in product(left_opts, right_opts):
                ans.append(TreeNode(mid, left, right))
        return ans
