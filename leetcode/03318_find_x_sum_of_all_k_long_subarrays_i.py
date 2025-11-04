def x_sum(counter, x):
    pairs = [(cnt, n) for n, cnt in counter.items()]
    pairs.sort()
    return sum(c * n for c, n in pairs[-x:])


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        ans = []
        c = Counter(nums[:k])
        left = 0
        ans.append(x_sum(c, x))
        for right in range(k, len(nums)):
            c[nums[left]] -= 1
            left += 1
            c[nums[right]] += 1
            ans.append(x_sum(c, x))
        return ans
