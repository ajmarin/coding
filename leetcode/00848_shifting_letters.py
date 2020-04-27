class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        answer = ['a'] * len(S)
        orda = ord('a')
        total_shifts = 0
        for i in range(len(S) - 1, -1, -1):
            total_shifts = (total_shifts + shifts[i]) % 26
            answer[i] = chr(orda + (ord(S[i]) - orda + total_shifts) % 26)
        return ''.join(answer)