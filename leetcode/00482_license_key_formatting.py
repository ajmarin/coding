class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        tmp = ''.join(S.upper().split('-'))
        mod = len(tmp) % K
        return '-'.join(filter(None, [tmp[:mod]] + list(tmp[i:i + K] for i in range(mod, len(tmp), K))))