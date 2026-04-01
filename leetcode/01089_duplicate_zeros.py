class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        last, dup = len(arr) - 1, 0
        for left in range(last + 1):
            if left > last - dup:
                break
            if arr[left] == 0:
                if left == last - dup:
                    arr[last] = 0
                    last -= 1
                    break
                dup += 1
        for i in range(last - dup, -1, -1):
            if arr[i] == 0:
                arr[i + dup] = 0
                dup -= 1
                arr[i + dup] = 0
            else:
                arr[i + dup] = arr[i]
