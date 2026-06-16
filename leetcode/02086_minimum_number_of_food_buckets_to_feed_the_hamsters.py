class Solution:
    def minimumBuckets(self, hamsters: str) -> int:
        hamsters = f"H{hamsters}H"
        if "HHH" in hamsters:
            return -1
        ans, i, end = 0, 1, len(hamsters)
        prev = "."
        while i < end:
            curr = hamsters[i]
            if prev == "H":
                ans += 1
                i += curr == "."
            prev = curr
            i += 1
        return ans
