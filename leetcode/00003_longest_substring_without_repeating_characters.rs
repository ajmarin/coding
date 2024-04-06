impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let chars: Vec<u8> = s.bytes().collect();
        let mut ans = 0;
        let mut left = 0;
        let mut seen = [false; 256];
        for (index, &c) in chars.iter().enumerate() {
            seen[c as usize] ^= true;
            if seen[c as usize] { continue; }
            ans = ans.max(index - left);
            while !seen[c as usize] {
                seen[chars[left] as usize] ^= true;
                left += 1;
            }
        }
        ans.max(chars.len() - left) as i32
    }
}

