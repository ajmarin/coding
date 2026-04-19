class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        seq = []
        for n in nums:
            if not seq or seq[-1] < n:
                seq.append(n)
            else:
                seq[bisect_left(seq, n)] = n
        return len(seq)
