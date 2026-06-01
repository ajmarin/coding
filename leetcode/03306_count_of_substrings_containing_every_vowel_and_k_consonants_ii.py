VOWELS = set("aeiou")


class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        next_cons = [0] * n
        next_idx = n
        for i in range(n - 1, -1, -1):
            next_cons[i] = next_idx
            if word[i] not in VOWELS:
                next_idx = i

        left = -1
        vowels = Counter()
        ans = cons = 0
        for right, c in enumerate(word):
            if c in VOWELS:
                vowels[c] += 1
            else:
                cons += 1
                while cons > k:
                    c = word[left := left + 1]
                    if c not in VOWELS:
                        cons -= 1
                    elif vowels[c] == 1:
                        del vowels[c]
                    else:
                        vowels[c] -= 1
            if cons != k or len(vowels) != 5:
                continue
            extra_subs = next_cons[right] - right
            while cons == k and len(vowels) == 5:
                ans += extra_subs
                c = word[left := left + 1]
                if c not in VOWELS:
                    cons -= 1
                elif vowels[c] == 1:
                    del vowels[c]
                else:
                    vowels[c] -= 1
        return ans
