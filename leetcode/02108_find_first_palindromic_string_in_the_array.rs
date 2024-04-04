impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        fn is_palindrome(s: &[u8]) -> bool {
            s.len() <= 1 || s[0] == s[s.len() - 1] && is_palindrome(&s[1..s.len() - 1])
        }
        match words.iter().find(|w| is_palindrome(w.as_bytes())) {
            Some(s) => s,
            None => ""
        }.to_string()
    }
}

