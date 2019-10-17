class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return len([c for c in S if c in J])