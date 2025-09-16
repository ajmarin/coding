class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            while ans and (g:= gcd(n, ans[-1])) != 1:
                n *= ans.pop() // g
            ans.append(n)
        return ans

