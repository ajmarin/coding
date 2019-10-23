class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        if not s:
            return ''
        # Find the last position of each character in s
        last_pos = [len(s)] * 32
        a = ord('a')
        for i, c in enumerate(s):
            last_pos[ord(c) - a] = i
        # Find the minimum last position mlp, so that range [mlp + 1, len(s)) has every other character.
        # Some character in the range [0, mlp] will have to stay, otherwise we'll miss s[mlp].
        # Since we want minimum lexicographical order, we'll take the min to preserve.
        c = min(s[:min(last_pos) + 1])
        # Now we simply put it in front and solve the problem for the remaining characters
        return c + self.removeDuplicateLetters(s[s.find(c):].replace(c, ''))