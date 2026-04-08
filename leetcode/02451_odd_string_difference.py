def compute_diff(word: str) -> List[int]:
    prev = ord(word[0])
    res = []
    for c in word[1:]:
        ordc = ord(c)
        res.append(ordc - prev)
        prev = ordc
    return res


class Solution:
    def oddString(self, words: List[str]) -> str:
        first = compute_diff(words[0])
        last = compute_diff(words[-1])
        if first == last:
            return next(word for word in words[1:-1] if compute_diff(word) != first)
        diff = compute_diff(words[1])
        return words[0 - (diff == first)]
