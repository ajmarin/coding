class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        total = sum(arr)
        if total % 3:
            return False
        n = len(arr)
        goal = total // 3

        curr, left = 0, 0
        while left < n:
            curr += arr[left]
            left += 1
            if curr == goal:
                break

        curr, right = 0, n - 1
        while right > -1:
            curr += arr[right]
            right -= 1
            if curr == goal:
                break

        return left <= right
