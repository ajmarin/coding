impl Solution {
    pub fn wonderful_substrings(word: String) -> i64 {
        let mut cnt = [0; 1 << 10];
        let mut m = 0;
        cnt[0] = 1;
        word.bytes().fold(0_i64, |ans, b| {
            m ^= 1 << (b - b'a') as usize;
            cnt[m] += 1;
            ans + cnt[m] - 1 + (0..10).fold(0, |r, i| r + cnt[m ^ (1 << i)])
        })
    }
}

