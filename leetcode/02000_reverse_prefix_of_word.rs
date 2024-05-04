impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        if let Some((head, tail)) = word.split_once(ch) {
            let ans: String = ch.into();
            return ans + &head.chars().rev().collect::<String>() + tail;
        }
        word
    }
}

