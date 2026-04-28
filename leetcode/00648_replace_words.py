class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        by_first = defaultdict(list)
        for root in dictionary:
            by_first[root[0]].append(root)
        for words in by_first.values():
            words.sort(key=lambda w: len(w))
        return " ".join(
            next((root for root in by_first[word[0]] if word.startswith(root)), word)
            for word in sentence.split(" ")
        )
