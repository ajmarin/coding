class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        biggest = -1
        for i in reversed(range(len(arr))):
            arr[i], biggest = biggest, arr[i] if arr[i] > biggest else biggest
        return arr
