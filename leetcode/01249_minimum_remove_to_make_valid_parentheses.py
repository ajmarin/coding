class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        tmp = ''
        balance = 0
        for c in s:
            if c.isalpha() or c == '(':
                tmp += c
            balance += c == '('
            if c == ')' and balance:
                balance -= 1
                tmp += c
        answer = ''
        balance = 0
        for c in tmp[::-1]:
            if c.isalpha() or c == ')':
                answer += c
            balance += c == ')'
            if c == '(' and balance:
                balance -= 1
                answer += c
        return answer[::-1]