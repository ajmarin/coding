import functools
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        answer = set()
        # Clear garbage on left and right
        first_open = s.find('(')
        last_close = s.rfind(')')
        if first_open != -1:
            s = s[:first_open].replace(')','') + s[first_open:]
        if last_close != -1:
            s = s[:last_close] + s[last_close:].replace('(','')
        OC = [')(', '()']
        level, balanced_level = 0, len(s)
        keys = [
            # Starting at s, level = balance = position = 0, up to len(s), direction
            (s, 0, 0, 0, len(s), 1),
            (s, 0, 0, len(s)-1, -1, -1),
        ]
        visited = set(keys)
        q = collections.deque(keys)
        while len(q):
            s, level, bal, L, R, d = q.popleft()
            if level > balanced_level:
                break
            oc = OC[(d + 1)>>1]
            for i in range(L, R, d):
                if s[i] == oc[0]: bal += 1
                elif s[i] == oc[1]:
                    news = s[:i] + s[i + 1:]
                    key = news, level + 1, bal, i - (d == -1), R - (d == 1), d
                    keyr = None
                    limits = [0 - (d == 1), len(news) - (d == 1)][::-d]
                    keyr = news, level + 1, 0, limits[0], limits[1], -d
                    if key not in visited:
                        visited.add(key)
                        q.append(key)
                    if keyr not in visited:
                        visited.add(keyr)
                        q.append(keyr)
                    bal -= 1
                    if bal < 0:
                        break
            if bal == 0 and level <= balanced_level:
                balanced_level = level
                answer.add(s)
        return answer