impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut p = 0;
        bank.iter().for_each(|row| {
            let ones = row.chars().filter(|c| *c == '1').count() as i32;
            ans += ones * p;
            if ones > 0 { p = ones; }
        });
        ans
    }
}

