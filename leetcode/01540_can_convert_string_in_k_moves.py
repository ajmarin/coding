ALPHABET_SIZE = ord('z') - ord('a') + 1

class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        
        counter = collections.Counter()
        for cs, ct in zip(s, t):
            diff = (ord(ct) - ord(cs) + ALPHABET_SIZE) % ALPHABET_SIZE
            counter[diff] += 1
        counter[0] = 0
        
        return all(key + (count - 1) * ALPHABET_SIZE <= k for key, count in counter.items())
