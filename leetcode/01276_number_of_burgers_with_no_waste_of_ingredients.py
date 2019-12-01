class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        jumbo = (tomatoSlices - 2 * cheeseSlices) // 2
        small = cheeseSlices - jumbo
        return [] if jumbo < 0 or small < 0 or 4 * jumbo + 2 * small != tomatoSlices else [jumbo, small]