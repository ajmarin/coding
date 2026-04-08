class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        volume = length * width * height
        is_bulky = any(val > 9999 for val in [length, width, height]) or volume >= 10**9
        if not is_bulky:
            return "Heavy" if mass > 99 else "Neither"
        return "Both" if mass > 99 else "Bulky"
