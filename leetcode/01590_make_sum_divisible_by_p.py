class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        rem = sum(nums) % p
        if rem == 0:
            return 0
        comp = p - rem
        ans, curr = len(nums), 0
        last = {0: -1}
        for i in range(ans):
            curr = (curr + nums[i]) % p
            need = (curr + comp) % p
            if need in last:
                size = i - last[need]
                ans = size if size < ans else ans
            last[curr] = i
        return ans if ans < len(nums) else -1
