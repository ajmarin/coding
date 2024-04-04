impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let n = n as usize;
        let mut steps = vec![100; 1 + n as usize];
        steps[0] = 0;

        for i in 0..n {
            let total_steps = steps[i] + 1;
            let mut pos = i + 1;
            let mut j = 1;
            while pos <= n {
                steps[pos] = steps[pos].min(total_steps);
                j += 2;
                pos += j;
            }
        }
        steps[n]
    }
}

