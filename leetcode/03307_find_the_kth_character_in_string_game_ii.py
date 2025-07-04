class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        k -= 1
        cnt = 0
        for n in operations:
            cnt += k & 1 & n
            k >>= 1
            if not k:
                break
        return chr(ord('a') + cnt % 26)

