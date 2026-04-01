class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        available = Counter(chars)
        ans = 0
        for w in words:
            c = Counter()
            for char in w:
                c[char] += 1
                if c[char] > available[char]:
                    break
            else:
                ans += len(w)
        return ans
