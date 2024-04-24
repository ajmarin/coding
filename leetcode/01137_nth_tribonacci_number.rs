impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let n = n as usize;
        let mut ans = vec![1; n + 1];
        ans[0] = 0;
        (3..=n).for_each(|i| { ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3]; });
        ans[n]
    }
}

