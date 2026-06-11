class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowel = {c: c in "aeiou" for c in ascii_lowercase}
        freq = [0]
        cnt = 0
        for w in words:
            if vowel[w[0]] and vowel[w[-1]]:
                cnt += 1
            freq.append(cnt)
        return [freq[r + 1] - freq[l] for l, r in queries]
