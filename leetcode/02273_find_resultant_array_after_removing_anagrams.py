class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        to_delete = {0}
        counters = {w: Counter(w) for w in words}
        while to_delete:
            to_delete = set()
            prev_c = Counter()
            for i, w in enumerate(words):
                curr_c = counters[w]
                if curr_c == prev_c:
                    to_delete.add(i)
                prev_c = curr_c
            words = [words[i] for i in range(len(words)) if i not in to_delete]
        return words
