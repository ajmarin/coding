class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        n = len(s1)
        s1, s2 = list(s1), list(s2)
        xs1, xs2 = sum(c == 'x' for c in s1), sum(c == 'x' for c in s2)
        if (xs1 + xs2) & 1:
            return -1
        answer = 0
        def swap(s1, i, s2, j):
            s1[i], s2[j] = s2[j], s1[i]
        def findAndSwap(z: int) -> bool:
            for j in range(z, len(s1)):
                if s1[j] == s2[j]:
                    continue
                if s1[j] == s1[i]:
                    swap(s1, j, s2, i)
                    return True
            return False
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                answer += 1
                if not findAndSwap(i + 1):
                    answer += 1
                    swap(s1, i, s2, i)
                    findAndSwap(i + 1)
        return answer