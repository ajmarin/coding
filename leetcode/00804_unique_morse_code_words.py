class Solution:
    MORSE = [
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--..",
    ]
    def to_morse(self, word: str) -> str:
        return ''.join(self.MORSE[ord(c) - ord('a')] for c in word)
        
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        return len(set(self.to_morse(word) for word in words))