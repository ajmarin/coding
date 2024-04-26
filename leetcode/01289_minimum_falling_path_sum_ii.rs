impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut dp = grid[0].clone();
        for row in grid[1..n].iter() {
            let mut s = dp.clone();
            s.sort_unstable();
            let (m1, m2) = (s[0], s[1]);
            for (dpv, c) in dp.iter_mut().zip(row) {
                *dpv = c + if *dpv != m1 { m1 } else { m2 };
            }
        }
        *dp.iter().min().unwrap()
    }
}

