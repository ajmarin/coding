class Solution:
    def majorityFrequencyGroup(self, s: str) -> str:
        fg = defaultdict(list)
        for c, count in Counter(s).items():
            fg[count].append(c)
        winner = max(fg, key=lambda cnt: (len(fg[cnt]), cnt))
        return "".join(fg[winner])
