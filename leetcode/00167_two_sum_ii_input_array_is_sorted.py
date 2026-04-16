class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while (total := numbers[left] + numbers[right]) != target:
            if total < target:
                left += 1
            else:
                right -= 1
        return [left + 1, right + 1]
