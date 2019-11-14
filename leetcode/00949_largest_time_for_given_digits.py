class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        ans = ()
        for hl, hr, ml, mr in itertools.permutations(A):
            hours = 10 * hl + hr
            mins = 10 * ml + mr
            if 0 <= hours <= 23 and 0 <= mins <= 59:
                ans = max(ans, (hours, mins))
        return f'{ans[0]:02d}:{ans[1]:02d}' if ans else ''