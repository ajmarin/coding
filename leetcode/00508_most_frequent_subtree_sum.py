class Solution:
    def __init__(self):
        self.counts_by_sum = Counter()

    def getSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        total = root.val + self.getSum(root.left) + self.getSum(root.right)
        self.counts_by_sum[total] += 1
        return total

    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        self.getSum(root)
        counts = self.counts_by_sum.most_common()
        ans = []
        for total, count in counts:
            if count != counts[0][1]:
                break
            ans.append(total)
        return ans
