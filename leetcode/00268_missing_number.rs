impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let len = nums.len() as i32;
        len * (len + 1) / 2 - nums.iter().fold(0, |sum, n| sum + n)
    }
}

