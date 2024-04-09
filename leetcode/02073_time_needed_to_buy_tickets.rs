impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let target = tickets[k as usize];
        tickets.iter().enumerate().fold(0, |ans, (index, &t)| {
            match index <= k as usize {
                true => ans + target.min(t),
                false => ans + t.min(target - 1),
            }
        })
    }
}

