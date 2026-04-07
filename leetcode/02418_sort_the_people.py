class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        ordering = sorted(range(len(names)), key=lambda i: -heights[i])
        return [names[i] for i in ordering]
