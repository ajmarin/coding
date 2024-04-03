impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        fn solve(board: &mut [Vec<char>], w: &[char], r: usize, c: usize) -> bool {
            if board[r][c] != w[0] { return false; }
            if w.len() == 1 { return true; }
            board[r][c] = '*';
            if r > 0 && solve(board, &w[1..], r - 1, c) { return true; }
            if c > 0 && solve(board, &w[1..], r, c - 1) { return true; }
            if r + 1 < board.len() && solve(board, &w[1..], r + 1, c) { return true; }
            if c + 1 < board[0].len() && solve(board, &w[1..], r, c + 1) { return true; }
            board[r][c] = w[0];
            false
        }

        let mut board = board;
        let word = word.chars().collect::<Vec<char>>();
        
        for row in 0..board.len() {
            for col in 0..board[0].len() {
                if solve(&mut board, &word, row, col) {
                    return true;
                }
            }
        }
        false
    }
}

