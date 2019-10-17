class Solution:
    NUMBER_TO_LETTERS = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz",
    }
    
    def recurse(self, digits: str, current: str, results: List[str]) -> None:
        if not digits:
            if current:
                results.append(current)
            return
        new_digits = digits[1:]
        for l in self.NUMBER_TO_LETTERS[int(digits[0])]:
            self.recurse(new_digits, current + l, results)
            
    def letterCombinations(self, digits: str) -> List[str]:
        results = []
        self.recurse(digits, '', results)
        return results