class Solution:
    def generateTag(self, caption: str) -> str:
        capitalize = lambda w: w[0].upper() + w[1:].lower()
        words = [w for w in caption.split(" ") if w]
        if not words:
            return "#"
        tag = f"#{words[0].lower()}" + "".join(capitalize(w) for w in words[1:])
        return tag[:100]
