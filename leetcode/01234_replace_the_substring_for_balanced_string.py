class Solution:
    def balancedString(self, s: str) -> int:
        pos = {'Q': 0, 'W': 1, 'E': 2, 'R': 3}
        count = [0] * 4
        length =len(s)
        balance = length // 4
        for c in s:
            count[pos[c]] += 1
        imbalance = [max(x - balance, 0) for x in count]
        if sum(imbalance) == 0:
            return 0
        answer = length
        replace = [None] * length
        ridx = 0
        start = 0
        for i in range(length):
            if count[pos[s[i]]] > balance:
                replace[ridx] = i
                ridx += 1
                imbalance[pos[s[i]]] -= 1
                if all(x <= 0 for x in imbalance):
                    while start < ridx and imbalance[pos[s[replace[start]]]] < 0:
                        imbalance[pos[s[replace[start]]]] += 1
                        start += 1
                    answer = min(answer, i - replace[start] + 1)
        return answer