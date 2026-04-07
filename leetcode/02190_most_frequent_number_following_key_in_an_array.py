class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        c = Counter()
        ans = highest = 0
        prev = -1
        for n in nums:
            if prev == key:
                c[n] += 1
                if c[n] > highest:
                    highest = c[n]
                    ans = n
            prev = n
        return ans
