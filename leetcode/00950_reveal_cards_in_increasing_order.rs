use std::collections::VecDeque;

impl Solution {
    pub fn deck_revealed_increasing(mut deck: Vec<i32>) -> Vec<i32> {
        let mut i = 0;
        let mut indices = VecDeque::from_iter(0..deck.len());
        let mut result = vec![0; deck.len()];

        deck.sort_unstable();
        while let Some(index) = indices.pop_front() {
            result[index] = deck[i];
            i += 1;
            if !indices.is_empty() {
                indices.rotate_left(1);
            }
        }

        result
    }
}

