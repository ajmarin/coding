class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        lt, gt = [], []
        cnt = 0
        for n in nums:
            if n < pivot:
                lt.append(n)
            elif n > pivot:
                gt.append(n)
            else:
                cnt += 1
        return lt + [pivot] * cnt + gt
