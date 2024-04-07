impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut low = 0;
        let mut high = 0;
        for c in s.chars() {
            low += 1 - 2 * (c != '(') as i8;
            high += 1 - 2 * (c == ')') as i8;
            if high < 0 { return false; }
            low = low.max(0);
        }
        low == 0
    }
}

