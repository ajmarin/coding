class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while sx < tx and sy < ty:
            if ty > tx: ty %= tx
            else: tx %= ty
        return (
            sx <= tx and (tx - sx) % sy == 0 and
            sy <= ty and (ty - sy) % sx == 0
        )