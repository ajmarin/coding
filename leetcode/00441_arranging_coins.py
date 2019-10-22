class Solution:
    '''
    x * (x + 1) / 2 <= n
    x**2 + x - 2 * n <= 0
    x = floor((-1 + sqrt(1 + 8n))/2)
    '''
    def arrangeCoins(self, n: int) -> int:
        return int(.5 * ((1 + (n << 3))**.5 - 1))