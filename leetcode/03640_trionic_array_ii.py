class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        N = len(nums)
        ans = -inf
        l = 0
        while l < N:
            while l < N - 1 and nums[l] >= nums[l + 1]:
                l += 1
            cand = prev = nums[l]
            p = l + 1
            while p < N and nums[p] > prev:
                cand += nums[p]
                prev = nums[p]
                p += 1
            q = p
            p -= 1
            while q < N and nums[q] < prev:
                cand += nums[q]
                prev = nums[q]
                q += 1
            r = q
            q -= 1
            while r < N and nums[r] > prev:
                cand += nums[r]
                prev = nums[r]
                r += 1
            r -= 1
            if l < p < q < r:
                ans = cand if cand > ans else ans
                while l < p - 1 and nums[l] < 0:
                    cand -= nums[l]
                    ans = cand if cand > ans else ans
                    l += 1
                while r > q + 1:
                    cand -= nums[r]
                    ans = cand if cand > ans else ans
                    r -= 1
                l = q
            else: break
        return ans

