class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        ans = invans = float("-inf")
        cur = inv = 0
        for n in A:
            cur += n
            inv -= n
            ans = max(ans, cur)
            invans = max(invans, inv)
            cur = max(cur, 0)
            inv = max(inv, 0)
        wrapped = sum(A) + invans    
        return max(ans, wrapped) if wrapped else ans