class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        banned = set(f for f, b in zip(fronts, backs) if f == b)
        return min((c for c in chain(fronts, backs) if c not in banned), default=0)
