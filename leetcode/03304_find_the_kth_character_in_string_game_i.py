class Solution:
    def kthCharacter(self, k: int) -> str:
        word = [0] * k
        pos = 1
        while pos < k:
            for n in word[:pos]:
                word[pos] = n + 1
                pos += 1
                if pos == k:
                    break
        return chr(word[k - 1] + ord('a'))

