class Solution:
    def longestCommonPrefix(self, words: List[str]) -> List[int]:
        def getCommonPrefix(w1: str, w2: str):
            count = 0
            for a, b in zip(w1, w2):
                if a != b:
                    break
                count += 1
            return count

        if len(words) == 1:
            return [0]

        lcp = [getCommonPrefix(w1, w2) for w1, w2 in zip(words, words[1:])]
        index, maxv = max(enumerate(lcp), key=itemgetter(1))
        ans = [maxv] * len(words)
        lcp[index] = 0
        ans[index] = max(lcp)
        ans[index + 1] = ans[index]
        for i in range(1, len(ans) - 1):
            ans[i] = max(ans[i], getCommonPrefix(words[i - 1], words[i + 1]))
        return ans

