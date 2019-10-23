class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        answer = ''
        pos = collections.defaultdict(collections.deque)
        for i, c in enumerate(s):
            pos[c].append(i)
        while pos:
            min_last = min(pos[c][-1] for c in sorted(pos))
            c = next(c for c in sorted(pos) if pos[c][0] <= min_last)
            trim = pos[c][0]
            del pos[c]
            for p in pos.values():
                while p[0] < trim:
                    p.popleft()
            answer += c
        return answer