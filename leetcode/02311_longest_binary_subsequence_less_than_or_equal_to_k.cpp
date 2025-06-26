class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, num = 0, zeroes = 0;
        const char *left = s.c_str() - 1;
        for (const char *c = s.c_str(); *c; ++c) {
            for (num = (num << 1) | (*c == '1'); num > k; )
                if (*++left == '1') num ^= 1 << (c - left);
                else ++zeroes;
            int tmp = zeroes + c - left;
            ans = tmp > ans ? tmp : ans;
        }
        return ans;
    }
};

