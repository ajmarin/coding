class Solution:
    def countPoints(self, rings: str) -> int:
        color_to_bit = dict([("R", 0), ("G", 1), ("B", 2)])
        rod_masks = [0] * 10
        for i in range(0, len(rings), 2):
            rod_masks[int(rings[i + 1])] |= 1 << color_to_bit[rings[i]]
        return sum(mask == 7 for mask in rod_masks)
