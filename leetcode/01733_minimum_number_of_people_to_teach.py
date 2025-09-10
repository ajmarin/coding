class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        languages = [set(), *(set(l) for l in languages)]
        mute = set()
        for a, b in friendships:
            if languages[a] & languages[b]: continue
            mute.add(a)
            mute.add(b)
        counts = Counter()
        for p in mute: counts.update(languages[p])
        return len(mute) - max(counts.values(), default=0)

