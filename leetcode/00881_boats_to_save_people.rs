impl Solution {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort_unstable();
        let (mut boats, mut left, mut right) = (0, 0, people.len() - 1);
        while left < right {
            if people[right] + people[left] <= limit {
                left += 1;
            }
            right -= 1;
            boats += 1;
        }
        boats + (left == right) as i32
    }
}

