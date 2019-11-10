class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        letter_count = collections.Counter(letters)
        score_for = {}
        ORDA = ord('a')
        for i, s in enumerate(score):
            score_for[chr(ORDA + i)] = s
        def doableWord(w: str):
            return all(letter_count[c] >= v for c, v in collections.Counter(w).items())
        words = list(filter(doableWord, words))
        word_score = [sum(score_for[c] for c in word) for word in words]
        def bt(index: int, score: int):
            max_score = score
            for i in range(index, len(words)):
                word = words[i]
                if doableWord(word):
                    for c in word:
                        letter_count[c] -= 1
                    max_score = max(max_score, bt(i + 1, score + word_score[i]))
                    for c in word:
                        letter_count[c] += 1
            return max_score
        return bt(0, 0)