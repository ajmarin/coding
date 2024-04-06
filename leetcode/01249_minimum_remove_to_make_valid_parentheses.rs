impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        fn make_valid(z: String, open: char, close: char) -> String {
            let mut count = 0;
            let mut valid = String::new();
            for c in z.chars().rev() {
                count += (c == open) as i32 - (c == close) as i32;
                if (c == close && count < 0) { count += 1; continue; }
                valid.push(c);
            }
            valid
        }
        make_valid(make_valid(s, ')', '('), '(', ')')
    }
}

