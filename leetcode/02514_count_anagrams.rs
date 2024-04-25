const P: usize = 1_000_000_007;

impl Solution {
    pub fn count_anagrams(s: String) -> i32 {
        // computes x such that ax = 1 (mod p)
        // leverages Fermat's little theorem: a^(p-1) = 1 (mod p)
        // IOW x = a^(p-2) % p
        fn invmod(mut a: usize, p: usize) -> usize {
            let (mut res, mut pow, mut exp) = (1, a, p - 2);
            while exp > 0 {
                if exp & 1 == 1 {
                    res = (res * pow) % p;
                }
                exp >>= 1;
                pow = (pow * pow) % p;
            }
            res
        }
        fn anagrams(word: &str) -> usize {
            let mut counts = vec![0; 128];
            word.bytes().for_each(|b| { counts[b as usize] += 1; });
            let mut res = (2..=word.len()).fold(1, |r, i| (r * i) % P);
            for c in counts {
                (2..=c).for_each(|i| { res = (res * invmod(i, P)) % P; })
            }
            res
        }
        s.split_ascii_whitespace()
            .fold(1_usize, |res, word| (res * anagrams(word) % P)) as i32
    }
}

