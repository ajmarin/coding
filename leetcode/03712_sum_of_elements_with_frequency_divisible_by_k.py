class Solution:
    def sumDivisibleByK(self, nums: List[int], k: int) -> int:
        return sum(n * c for c, n in Counter(nums).items() if n % k == 0)
