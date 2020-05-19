class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count = collections.Counter(s1)
        goal = len(count)
        l1 = len(s1)
        for i, c in enumerate(s2):
            goal -= (count[c] == 1) - (count[c] == 0)
            count[c] -= 1
            if i >= l1:
                c = s2[i - l1]
                goal -= (count[c] == -1) - (count[c] == 0)
                count[c] += 1
            if goal == 0:
                return True
        return False