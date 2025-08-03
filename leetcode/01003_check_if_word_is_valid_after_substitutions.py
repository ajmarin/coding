class Solution:
    def isValid(self, s: str) -> bool:
        q = deque()
        for x in s:
            if x == 'c':
                if len(q) < 2 or q.pop() != 'b' or q.pop() != 'a':
                    return False
            else: q.append(x)
        return not len(q)

