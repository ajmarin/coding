class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        N = len(nums)
        def bt(seq: List[int], index: int):
            if len(seq) > 1:
                ans.add(tuple(seq))
            if index == N:
                return
            for i in range(index, N):
                if not seq or nums[i] >= seq[-1]:
                    seq.append(nums[i])
                    bt(seq, i + 1)
                    seq.pop()
        bt(collections.deque(), 0)
        return ans