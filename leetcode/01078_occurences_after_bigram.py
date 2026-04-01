class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ans, state = [], 0
        for word in text.split(" "):
            if state == 0 and word == first:
                state = 1
            elif state == 1:
                if word == second:
                    state = 2
                elif word != first:
                    state = 0
            elif state == 2:
                state = 0 if word != first else 1 + (word == second)
                ans.append(word)
        return ans
