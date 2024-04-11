impl Solution {
    pub fn remove_kdigits(num: String, mut k: i32) -> String {
        let mut ans = String::new();
        for c in num.chars() {
            while k > 0 && !ans.is_empty() {
                let p = ans.pop().unwrap();
                if p > c { k -= 1; }
                else { ans.push(p); break; }
            }
            ans.push(c);
        }
        ans.truncate(ans.len() - k as usize);
        ans = ans.trim_start_matches('0').to_string();
        if ans.len() > 0 { ans } else { "0".to_string() }
    }
}

