impl Solution {
    pub fn put_marbles(mut w: Vec<i32>, k: i32) -> i64 {
        (0..w.len() - 1).for_each(|i| { w[i] += w[i + 1]; });
        w.pop();
        w.sort_unstable();
        (0..k as usize - 1)
            .fold(0_i64, |ans, i| ans + w[w.len() - i - 1] as i64 - w[i] as i64)
    }
}

