impl Solution {
    pub fn make_good(s: String) -> String {
        let mut s: Vec<u8> = s.bytes().collect();
        let mut improved = s.len() > 0;
        while s.len() > 0 {
            improved = false;
            for i in 0..s.len() - 1 {
                if s[i] != s[i + 1] && s[i] | 32u8 == s[i + 1] | 32u8 {
                    s.remove(i + 1);
                    s.remove(i);
                    improved = true;
                    break;
                }
            }
            if !improved { break; }
        }
        String::from_utf8(s).unwrap()
    }
}

