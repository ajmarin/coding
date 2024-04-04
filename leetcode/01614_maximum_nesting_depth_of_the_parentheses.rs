impl Solution {
    pub fn max_depth(s: String) -> i32 {
        s.chars().fold((0, 0), |(d, md), c| {
            let d = d + (c == '(') as i32 - (c == ')') as i32;
            (d, if d > md { d } else { md })
        }).1
    }
}

