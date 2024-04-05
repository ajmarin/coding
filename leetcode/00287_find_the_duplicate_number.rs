impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut c = vec![0; nums.len()];
        nums.iter().for_each(|n| c[*n as usize] += 1);
        c.iter().enumerate().find(|t| *t.1 > 1).unwrap().0 as i32
    }
}

