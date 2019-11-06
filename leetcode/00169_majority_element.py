class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count, answer = 0, 0
        for n in nums:
            if not count:
                answer, count = n, 1
            else:
                count += (n == answer) - (n != answer)
        return answer