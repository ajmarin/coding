class Solution:
    def smash(self, stones: List[int]) -> List[int]:
        y = max(stones)
        stones.remove(y)
        x = max(stones)
        stones.remove(x)
        if x != y:
            stones.append(y - x)
        
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            self.smash(stones)
        return stones[0] if stones else 0