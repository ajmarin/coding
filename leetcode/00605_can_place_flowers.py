class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
        l = len(flowerbed)
        flowerbed += [0]
        prev = 0
        for i in range(l):
            if prev == flowerbed[i] == flowerbed[i + 1] == 0:
                n -= 1
                flowerbed[i] = 1
                if n == 0:
                    break
            prev = flowerbed[i]
        return n == 0
