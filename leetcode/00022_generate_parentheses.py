class Solution:
    def solve(self, s: str, o: int, c: int, solution: List[str]) -> List[str]:
        if o == 0 and c == 0:
            solution.append(s)
        if o > 0:
            self.solve(s + '(', o - 1, c, solution)
        if c > o:
            self.solve(s + ')', o, c - 1, solution)
            
    def generateParenthesis(self, n: int) -> List[str]:
        solution = []
        self.solve('', n, n, solution)
        return solution