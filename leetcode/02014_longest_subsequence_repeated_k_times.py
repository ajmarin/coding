class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        maxlen = min(len(s) // k, 7)
        counts = Counter(s)

        def validate(candidate: str):
            it = iter(s)
            return all(c in it for c in candidate * k)


        def bt(candidate: str, chars: List[str]):
            best = candidate
            for c in chars:
                if counts[c] < k:
                    continue
                new = candidate + c
                if not validate(new):
                    continue
                counts[c] -= k
                res = bt(new, chars)
                if len(res) > len(best):
                    best = res
                    if len(best) == maxlen:
                        break
                counts[c] += k
            return best


        chars = sorted([c for c in counts if counts[c] >= k])
        return bt("", chars[::-1])

