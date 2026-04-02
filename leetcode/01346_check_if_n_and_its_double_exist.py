class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for n in arr:
            if 2 * n in seen or (n % 2 == 0 and n >> 1 in seen):
                return True
            seen.add(n)
        return False
