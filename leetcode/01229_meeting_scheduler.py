class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        i1, i2 = 0, 0
        n1, n2 = len(slots1), len(slots2)
        while i1 < n1 and i2 < n2:
            start = max(slots1[i1][0], slots2[i2][0])
            end = start + duration
            wf1 = end <= slots1[i1][1]
            wf2 = end <= slots2[i2][1]
            if wf1 and wf2:
                return [start, end]
            i1 += not wf1
            i2 += not wf2
        return []