class Solution:
    def longestBalanced(self, s: str) -> int:
        totals = [s.count("0"), 0]
        totals[1] = len(s) - totals[0]

        best = balance = 0
        first = defaultdict(list)
        first[0] = [-1]
        for right, c in enumerate(s):
            balance += (c == "1") - (c == "0")
            for target in (balance, balance - 2, balance + 2):
                for left in first[target]:
                    size = right - left
                    if size <= best:
                        continue
                    diff = balance - target
                    local = [0, (size + diff) >> 1]
                    local[0] = size - local[1]
                    idx = (2 - diff) >> 2
                    if not diff or totals[idx] > local[idx]:
                        best = size if size > best else best
            if len(first[balance]) < 2:
                first[balance].append(right)
        return best
