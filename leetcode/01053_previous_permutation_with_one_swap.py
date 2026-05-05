class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        s = [n - 1]
        for i in range(n - 2, -1, -1):
            if arr[i] < arr[s[-1]]:
                s.append(i)
            elif arr[i] == arr[s[-1]]:
                s[-1] = i
            else:
                while s and arr[i] > arr[s[-1]]:
                    si = s.pop()
                arr[i], arr[si] = arr[si], arr[i]
                break
        return arr
