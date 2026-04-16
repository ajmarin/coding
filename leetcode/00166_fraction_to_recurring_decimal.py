class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        sign = "-" if (numerator < 0) ^ (denominator < 0) else ""
        numerator = abs(numerator)
        denominator = abs(denominator)

        full = numerator // denominator
        numerator %= denominator
        fractional = []
        mapping = {}
        rep_start = -1
        while numerator:
            numerator *= 10
            div = numerator // denominator
            numerator %= denominator
            if (div, numerator) in mapping:
                rep_start = mapping[div, numerator]
                break
            mapping[div, numerator] = len(fractional)
            fractional.append(div)
        fractional = "".join(str(d) for d in fractional)
        if rep_start != -1:
            fractional = f"{fractional[:rep_start]}({fractional[rep_start:]})"
        return sign + (str(full) if not fractional else f"{full}.{fractional}")
