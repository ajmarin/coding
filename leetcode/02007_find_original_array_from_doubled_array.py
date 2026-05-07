class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        c = Counter(changed)
        changed.sort()
        ans = []
        for n in changed:
            if not c[n]:
                continue
            c[n] -= 1
            if c[n << 1]:
                ans.append(n)
                c[n << 1] -= 1
            else:
                return []
        return ans
