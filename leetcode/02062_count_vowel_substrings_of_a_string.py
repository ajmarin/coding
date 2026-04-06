VOWELS = set("aeiou")


class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        n = len(word)
        ans = 0
        for start in range(n - 4):
            if word[start] not in VOWELS:
                continue
            count = Counter()
            missing = 5
            for i in range(start, n):
                c = word[i]
                if c not in VOWELS:
                    break
                count[c] += 1
                missing -= count[c] == 1
                ans += missing == 0
        return ans
