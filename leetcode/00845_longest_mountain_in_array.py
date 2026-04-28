class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        longest = 0
        inc = dec = 0
        for a, b in pairwise(arr):
            if a == b:
                inc = dec = 0
                continue
            if dec:
                if a > b:
                    dec += 1
                    longest = longest if longest > inc + dec else inc + dec
                else:
                    dec = 0
                    inc = 1
            elif a < b:
                inc += 1
            elif inc:
                dec = 1
                longest = longest if longest > inc + dec else inc + dec
        return longest + (longest > 0)
