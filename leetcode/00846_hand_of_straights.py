class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        hand.sort()
        c = Counter(hand)
        for x in hand:
            if not c[x]:
                continue
            for i in range(x, x + groupSize):
                if not c[i]:
                    return False
                c[i] -= 1
        return True
