class Solution:
    def flipLights(self, n: int, m: int) -> int:
        if m == 0: # did nothing, everything is on
            return 1
        if n == 1: # only one light [on, off]
            return 2
        if m == 1: # if there are two lights, 4th operation is same as 3rd
            return 3 + (n > 2)
        # For more than 3 lights, the problem is the same as 3 lights
        # Representing the state as 3 bits, e.g. 100 for [on, off, off]
        # First bit is controlled by difference of (3k + 1) and odd flips
        # Second bit is controlled by even flips
        # Third bit is controlled by odd flips
        # With only two operations, we cannot turn off only first bit
        return (4 << (n > 2)) - (n > 2 and m == 2)