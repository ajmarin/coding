class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        ans = 10**6
        c = Counter()
        highest_count = 0

        for n in nums:
            if n & 1:
                continue
            c[n] += 1
            if c[n] > highest_count or (c[n] == highest_count and n < ans):
                highest_count = c[n]
                ans = n
        return ans if highest_count else -1
