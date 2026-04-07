class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        c = Counter(ranks)
        max_same = max(Counter(ranks).values())
        if max_same >= 3:
            return "Three of a Kind"
        if max_same == 2:
            return "Pair"
        return "High Card"
