class Solution:
    def assignElements(self, groups: List[int], elements: List[int]) -> List[int]:
        mapping = {}
        cap = max(groups) + 1
        for i, e in enumerate(elements):
            if e in mapping:
                continue
            for j in range(e, cap, e):
                mapping.setdefault(j, i)
        return [mapping.get(g, -1) for g in groups]
