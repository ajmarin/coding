impl Solution {
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let (rows, cols) = (land.len(), land[0].len());
        for i in 0..rows {
            for j in 0..cols {
                if land[i][j] != 1 { continue; }
                land[i][j] = 2;
                let (mut r, mut c) = (i, j);
                while r < rows - 1 && land[r + 1][c] == 1 {
                    r += 1;
                    land[r][c] = 2;
                }
                while c < cols - 1 && land[r][c + 1] == 1 {
                    c += 1;
                    for row in i..=r { land[row][c] = 2; }
                }
                ans.push(vec![i as i32, j as i32, r as i32, c as i32]);
            }
        }
        ans
    }
}

