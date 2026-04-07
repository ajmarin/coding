class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        ordval, seen = ord("a"), set(" ")
        mapping = {" ": " "}
        for c in key:
            if c in seen:
                continue
            seen.add(c)
            mapping[c] = chr(ordval)
            ordval += 1
        return "".join(mapping[c] for c in message)
