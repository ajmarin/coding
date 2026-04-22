class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        n = len(queries[0])

        def within_two_edits(word: str):
            for dword in dictionary:
                count = 0
                for i in range(n):
                    if word[i] != dword[i] and (count := count + 1) > 2:
                        break
                if count < 3:
                    return True
            return False

        return [w for w in queries if within_two_edits(w)]
