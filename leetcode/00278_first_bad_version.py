class Solution:
    def firstBadVersion(self, n):
        left, right = 1, n + 1
        while left < right:
            mid = (left + right) >> 1
            if not isBadVersion(mid):
                left = mid + 1
            else:
                right = mid    
        return left