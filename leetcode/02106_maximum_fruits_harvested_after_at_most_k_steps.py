class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        def get_steps(left, right):
            left_first = startPos - left + right - left
            right_first = right - startPos + right - left
            return left_first if left_first < right_first else right_first

        low = bisect_left(fruits, [startPos - k, 0])
        high = bisect_right(fruits, [startPos + k + 1, ])
        ans = cand = 0
        left = low
        for right in range(low, high):
            pos, amount = fruits[right]
            cand += amount
            while left <= right and get_steps(fruits[left][0], pos) > k:
                cand -= fruits[left][1]
                left += 1
            ans = cand if cand > ans else ans
        return ans

