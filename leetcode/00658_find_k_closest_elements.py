class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        L = len(arr)
        left = bisect.bisect_left(arr, x)
        left -= left and left < L and x <= arr[left - 1] + arr[left]
        if left == 0:
            return arr[:k]
        if left == L:
            return arr[-k:]
        right = left + 1
        s = arr[left] + arr[right]
        x <<= 1
        for _ in range(k):
            if x > s:
                s -= arr[right]
                right += 1
                if right == L:
                    break
                s += arr[right]
            else:
                s -= arr[left]
                left -= 1
                if left == -1:
                    right = k
                    break
                s += arr[left]
        return arr[right - k:right]