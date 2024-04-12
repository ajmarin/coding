impl Solution {
    pub fn circular_array_loop(mut nums: Vec<i32>) -> bool {
        const VISITED: i32 = 1001;

        let n = nums.len();
        let sign = |n| if n < 0 { -1 } else { 1 };

        for i in 0..n {
            let current_sign = sign(nums[i]);
            let cycle_id = VISITED + i as i32;
            let mut pos = i;
            while nums[pos] < VISITED {
                let next = (pos + n + nums[pos] as usize) % nums.len();
                nums[pos] = cycle_id;
                if next == pos { break; }
                if nums[next] == cycle_id { return true; }
                if sign(nums[next]) != current_sign { break; }

                pos = next;
            }
        }
        false
    }
}

