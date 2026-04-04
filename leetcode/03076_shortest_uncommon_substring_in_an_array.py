class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        def find_answer(index):
            word = arr[index]
            l = len(word)
            ans = ""
            for length in range(1, l + 1):
                for start in range(l - length + 1):
                    cand = word[start : start + length]
                    if all(cand not in w for i, w in enumerate(arr) if i != index):
                        if ans:
                            ans = cand if cand < ans else ans
                        else:
                            ans = cand
                if ans:
                    break
            return ans

        return [*map(find_answer, range(len(arr)))]
