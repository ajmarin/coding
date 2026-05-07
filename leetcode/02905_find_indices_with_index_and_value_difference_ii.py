class Solution:
    def findIndices(
        self, nums: List[int], indexDifference: int, valueDifference: int
    ) -> List[int]:
        high = left = low = 0
        lown = highn = nums[0]
        for i in range(indexDifference, len(nums)):
            x = nums[left]
            if x < lown:
                lown = x
                low = left
            elif x > highn:
                highn = x
                high = left
            left += 1
            curr = nums[i]
            if curr > highn:
                if curr - lown >= valueDifference:
                    return [low, i]
            elif curr < lown:
                if highn - curr >= valueDifference:
                    return [high, i]
            elif curr - lown >= valueDifference:
                return [low, i]
            elif highn - curr >= valueDifference:
                return [high, i]
        return [-1, -1]
