class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        index = dict((num, i) for i, num in enumerate(arr2))
        arr1.sort(key=lambda n: index.get(n, n + len(index)))
        return arr1
