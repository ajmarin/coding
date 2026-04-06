class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        covered = [False] * 55
        for start, end in ranges:
            for i in range(start, end + 1):
                covered[i] = True
        return all(covered[left : right + 1])
