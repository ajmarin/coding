class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count = collections.Counter(s1)
        L1, L2 = len(s1), len(s2)
        left, right = 0, 0
        while left < L2:
            # Find begin candidate
            while left < L2 and not count[s2[left]]:
                left += 2
            # Find end candidate
            right = left
            while right < L2:
                c = s2[right]
                if count[c]:
                    count[c] -= 1
                    right += 1
                    if right - left == L1:
                        return True
                elif left < right:
                    count[s2[left]] += 1
                    left += 1
                else:
                    break
            while left < right:
                count[s2[left]] += 1
                left += 1
            left += 1
        return False