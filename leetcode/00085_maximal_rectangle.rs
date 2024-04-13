impl Solution {
    fn biggest_rect(hist: &[i32]) -> i32 {
        let mut s = Vec::with_capacity(hist.len());
        let mut ans = 0;

        for (i, &height) in hist.iter().enumerate() {
            while let Some(&j) = s.last() {
                let h = hist[j];
                if height >= h { break; }
                s.pop();
                let w = if s.is_empty() { i } else { i - *s.last().unwrap() - 1 } as i32;
                ans = ans.max(h * w);
            }
            s.push(i);
        }
        ans
    }

    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        let mut hist = vec![0; 1 + matrix[0].len()];
        matrix.iter()
            .map(|row| {
                for (i, &c) in row.iter().enumerate() {
                    hist[i] = if c == '0' { 0 } else { hist[i] + 1 }
                }
                Self::biggest_rect(&hist)
            })
            .max().unwrap_or(0)
    }
}

