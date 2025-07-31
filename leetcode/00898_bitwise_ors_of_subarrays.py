class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        ans, pref = set(), set()
        for num in arr:
            pref = {z | num for z in pref} | { num }
            ans.update(pref)
        return len(ans)

