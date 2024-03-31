impl Solution {
    pub fn count_alternating_subarrays(nums: Vec<i32>) -> i64 {
        let mut total = 0;
        let mut prev = -1;
        let mut size = 0;
        for n in &nums {
            if *n == prev {
                total += size * (size + 1) / 2;
                size = 0;
            }
            size += 1;
            prev = *n;
        }
        return total + size * (size + 1) / 2;
    }
}

