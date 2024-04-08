impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let mut wants = students.iter().fold([0, 0], |mut w, &s| { w[s as usize] += 1; w });
        for (index, &sandwich) in sandwiches.iter().enumerate() {
            if (wants[sandwich as usize] == 0) {
                return (sandwiches.len() - index) as i32;
            }
            wants[sandwich as usize] -= 1;
        }
        0
    }
}

