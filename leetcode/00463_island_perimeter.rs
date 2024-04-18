impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    ans += (i == 0 || grid[i - 1][j] == 0) as i32;
                    ans += (j == 0 || grid[i][j - 1] == 0) as i32;
                }
            }
        }
        2 * ans
    }
}

