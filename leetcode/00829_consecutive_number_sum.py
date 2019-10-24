class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        # N is the sum of consecutive numbers, starting at x with k numbers:
        # N = sum(x + (x + 1) + ... + (x + k - 1))
        # N = k/2 * (x + x + k - 1)
        # 2*N = k * (k + 2*x - 1)
        # 2*N - k * k = k * (2*x - 1)
        # Since k > 0, we need to find all solutions for:
        # (2*N - k * k) % k == 0 such that (2*N - k*k) / k is odd
        # k * k is certainly divisible by k, so we don't need that there:
        # (2*N) % k == 0 and ((2*N) / k - k) & 1
        N <<= 1
        return sum(N % k == 0 and (N // k - k) & 1 for k in range(1, math.ceil(N**.5)))