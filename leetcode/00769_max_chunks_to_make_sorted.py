class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        chunks, n = 0, len(arr)
        i = 0
        while i < n:
            chunks += 1
            if i != arr[i]:
                maxj = arr[i]
                while i < maxj:
                    j = arr[i]
                    maxj = max(maxj, j)
                    arr[i], arr[j] = arr[j], arr[i]
                    i += j == i
            i += 1
        return chunks