class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = last = 0
        for floor in bank:
            curr = floor.count("1")
            if curr:
                ans += curr * last
                last = curr
        return ans
