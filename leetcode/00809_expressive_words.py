class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        def isExtension(ext: str, word: str):
            i, I, j, J = 0, len(ext), 0, len(word)
            def get_reps(s: str, index: int):
                L, reps = len(s), 1
                while index + reps < L and s[index + reps] == s[index]:
                    reps += 1
                return reps
            while i < I and j < J:
                if ext[i] != word[j]:
                    return False
                ext_reps = get_reps(ext, i)
                word_reps = get_reps(word, j)
                if ext_reps == word_reps or (ext_reps > max(2, word_reps)):
                    i = i + ext_reps
                    j = j + word_reps
                else:
                    return False
            return i == I and j == J
        return sum(isExtension(S, word) for word in words)