from collections import Counter
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        answer = 0
        count = Counter([0])
        s = 0
        for n in nums:
            s += n
            answer += count[s - k]
            count[s] += 1
        return answer