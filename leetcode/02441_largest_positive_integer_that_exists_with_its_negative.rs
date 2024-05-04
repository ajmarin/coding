impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut exists = [false; 2048];
        for n in nums.iter() {
            exists[(n + 1000) as usize] = true;
        }
        let mut ans = -1;
        for n in nums {
            if n > 0 && exists[(1000 - n) as usize] {
                ans = ans.max(n);
            }
        }
        ans
    }
}

