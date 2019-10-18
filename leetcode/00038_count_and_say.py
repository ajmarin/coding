class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        for i in range(n - 1):
            p = s[0]
            news = []
            count = 0
            for c in s:
                if c == p:
                    count += 1
                else:
                    news.extend([str(count), p])
                    p = c
                    count = 1
            if count:
                news.extend([str(count), p])
            s = ''.join(news)
        return s