CODE_RE = re.compile("^[a-zA-Z0-9_]+$")
VALID_BUSINESSES = {"electronics", "grocery", "pharmacy", "restaurant"}

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        valid = [
            i for i in range(len(code))
            if isActive[i] and businessLine[i] in VALID_BUSINESSES and CODE_RE.match(code[i])
        ]
        valid.sort(key=lambda i: (businessLine[i], code[i]))
        return [code[i] for i in valid]

