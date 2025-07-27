class Solution:
    def numOfSubsequences(self, s: str) -> int:
        N = len(s)
        prefL = [0] * (N + 3)
        prefLC = [0] * (N + 3)
        l = lc = lct = 0
        suffT = [0] * (N + 3)
        suffCT = [0] * (N + 3)
        t = ct = 0
        for i in range(N):
            match s[i]:
                case 'L': l += 1
                case 'C': lc += l
                case 'T': lct += lc
                case _: pass
            x = i + 1
            prefL[x] = l
            prefLC[x] = lc

            x = N - i - 1
            match s[x]:
                case 'T': t += 1
                case 'C': ct += t
                case _: pass
            suffT[x] = t
            suffCT[x] = ct

        ans = base = lct
        for i in range(N + 1):
            cand = suffCT[i]  # add L
            addC = prefL[i] * suffT[i]
            cand = addC if addC > cand else cand
            cand = prefLC[i] if prefLC[i] > cand else cand
            cand += base
            ans = cand if cand > ans else ans
        return ans

