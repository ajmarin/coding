class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total = sum(apple)
        capacity.sort(reverse=True)
        cap = 0
        for count, c in enumerate(capacity):
            if (cap := cap + c) >= total:
                break
        return count + 1
