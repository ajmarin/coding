impl Solution {
    pub fn max_bottles_drunk(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut drunk = 0;
        let mut cost = num_exchange;
        let mut bottles_left = num_bottles;
        while bottles_left >= cost {
            drunk += cost;
            bottles_left -= (cost - 1);
            cost += 1;      
        }
        return drunk + bottles_left;
    }
}

