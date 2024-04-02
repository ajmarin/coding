impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        let mut winner = arr[0];
        let mut wins = -1;
        for n in arr {
            if n > winner {
                winner = n;
                wins = 0;
            }
            wins += 1;
            if wins == k {
                break;
            }
        }
        winner 
    }
}

