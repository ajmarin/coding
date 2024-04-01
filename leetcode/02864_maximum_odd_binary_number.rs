impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let ones = s.chars().filter(|c| *c == '1').count();
        "1".repeat(ones - 1) + &"0".repeat(s.len() - ones) + "1"
    }
}

