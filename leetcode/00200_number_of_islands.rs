use std::collections::VecDeque;

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut ans = 0;
        let mut q = VecDeque::<(usize, usize)>::new();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] != '1' { continue; }
                ans += 1;
                q.push_back((i, j));
                while !q.is_empty() {
                    let (r, c) = q.pop_front().unwrap();
                    if grid[r][c] == '*' { continue; }
                    grid[r][c] = '*';
                    if r > 0 && grid[r - 1][c] == '1' {
                        q.push_back((r - 1, c));
                    }
                    if r < rows - 1 && grid[r + 1][c] == '1' {
                        q.push_back((r + 1, c));
                    }
                    if c > 0 && grid[r][c - 1] == '1' {
                        q.push_back((r, c - 1));
                    }
                    if c < cols - 1 && grid[r][c + 1] == '1' {
                        q.push_back((r, c + 1));
                    }
                }
            }
        }
        ans
    }
}

