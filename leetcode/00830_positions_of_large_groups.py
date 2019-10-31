class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        left = 0
        answer = collections.deque()
        for c, g in itertools.groupby(S):
            cnt = len(list(g))
            if cnt >= 3:
                answer.append((left, left + cnt - 1))
            left += cnt
        return answer