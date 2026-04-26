class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        lowest = second = 10**6
        for arr in arrays:
            num = arr[0]
            if num < lowest:
                lowest, second = num, lowest
            elif num < second:
                second = num

        ans = 0
        for arr in arrays:
            high = arr[-1]
            low = lowest if lowest != arr[0] else second
            ans = high - low if high - low > ans else ans
        return ans
